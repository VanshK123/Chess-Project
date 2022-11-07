#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using Student::ChessBoard;
using Student::ChessPiece;

/*
void printlist(std::list<ChessPiece *> const &list);

void printlist(std::list<ChessPiece *> const &list)
{

  for (auto const &i : list)
  {
    std::cout << "COLOR " << i->getColor() << " POS " << i->getRow() << i->getColumn() << std::endl;
  }
}*/

ChessBoard::ChessBoard(int numRow, int numCol)
{

  board.resize(numRow, std::vector<ChessPiece *>(numCol, NULL));
  numRows = numRow;
  numCols = numCol;
  return;
}

ChessBoard::ChessBoard(ChessBoard &other)
{
}

ChessBoard::~ChessBoard()
{
  // board.clear();

  for (int i = 0; i < numRows; i++)
  {
    for (int j = 0; j < numCols; j++)
    {
      delete board.at(i).at(j);
    }
  }
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn)
{

  if (startRow < 0 || startColumn < 0 || startRow >= numRows || startColumn >= numCols)
  {
    return;
  }
  if (isOccupied(startRow, startColumn))
  {
    removeChessPiece(startRow, startColumn);
  }

  ChessPiece *piece = NULL;
  // printf("TYPE: %d COLOR: %d\n", ty, col);

  if (ty == Type::Bishop)
  {
    // printf("BISHOP row%d col: %d\n", startRow, startColumn);

    piece = new BishopPiece(*this, col, startRow, startColumn);
  }
  if (ty == Type::Pawn)
  {
    // printf("Pawn row%d col: %d\n", startRow, startColumn);
    piece = new PawnPiece(*this, col, startRow, startColumn);
  }
  if (ty == Type::Rook)
  {
    // printf("Rook row%d col: %d\n", startRow, startColumn);
    piece = new RookPiece(*this, col, startRow, startColumn);
  }
  if (ty == Type::King)
  {
    // printf("King row%d col: %d\n", startRow, startColumn);
    piece = new KingPiece(*this, col, startRow, startColumn);
    if (col == Color::White)
    {
      whiteKing = (KingPiece*)piece;
    }
    else
    {
      blackKing = (KingPiece*)piece;
    }
    printf("KING CREATED\n");
    printf("KING COLOR %d\n", piece->getColor());
  }

  if (isOccupied(startRow, startColumn))
  {
    delete board.at(startRow).at(startColumn);
    board.at(startRow).at(startColumn) = piece;
  }
  else
  {
    board.at(startRow).at(startColumn) = piece;
  }

  if (piece->getColor() == Color::Black)
  {
    blackPieces.emplace_back(piece);
  }
  else
  {
    whitePieces.emplace_back(piece);
  }
  /*
  std::cout << "blackPieces" << std::endl;
  printlist(blackPieces);
  std::cout << "whitePieces" << std::endl;
  printlist(whitePieces);
  */
  // delete[] piece;
  return;
}

void ChessBoard::removeChessPiece(int row, int column)
{
  if (board.at(row).at(column) == nullptr)
  {
    return;
  }
  // check if is king, remove from king pointer
  if (board.at(row).at(column)->getType() == Type::King)
  {
    printf("KING REMOVED\n");
    if (board.at(row).at(column)->getColor() == Color::White)
    {
      whiteKing = nullptr;
    }
    else
    {
      blackKing = nullptr;
    }
  }

  // remove from color list
  if (getPiece(row, column)->getColor() == Color::Black)
  {
    blackPieces.remove(getPiece(row, column));
  }
  else
  {
    whitePieces.remove(getPiece(row, column));
  }
  delete board.at(row).at(column);
  board.at(row).at(column) = nullptr;

  return;
}

bool ChessBoard::isOccupied(int row, int column)
{
  if (board.at(row).at(column) != nullptr)
  {
    return true;
  }

  return false;
}

bool ChessBoard::isOccupiedWithColor(int row, int column, Color color)
{

  if (board.at(row).at(column) != nullptr && color == getPiece(row, column)->getColor())
  {
    return true;
  }
  return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
  printf("From %d %d to %d %d\n", fromRow, fromColumn, toRow, toColumn);
  if (toRow > numRows || toColumn > numCols || toRow < 0 || toColumn < 0 || fromRow > numRows || fromColumn > numCols || fromRow < 0 || fromColumn < 0)
  {
    printf("fails bounds check\n");
    return false;
  }

  if (getPiece(fromRow, fromColumn) == NULL)
  {
    printf("fails null check\n");
    return false;
  }
  if (fromRow == toRow && fromColumn == toColumn)
  {
    printf("fails same check\n");
    return false;
  }
  /*
  if (getPiece(fromRow, fromColumn)->canMoveToLocation(toRow, toColumn))
  {
    printf("From %d %d to %d %d\n", fromRow, fromColumn, toRow, toColumn);
  }*/
  /*
  else{
    printf("FALSE ");
    printf("From %d %d to %d %d\n",fromRow,fromColumn,toRow,toColumn);
  }*/
  bool canmove = getPiece(fromRow, fromColumn)->canMoveToLocation(toRow, toColumn);
  if (canmove)
  {
    printf("\n---TRUE ");
    printf("From %d %d to %d %d\n", fromRow, fromColumn, toRow, toColumn);
  }
  return canmove;
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
  printf("Forcing From %d %d to %d %d\n", fromRow, fromColumn, toRow, toColumn);

  // does nothing if not occupied
  if (!isOccupied(fromRow, fromColumn))
  {
    return;
  }

  // removes piece from from location list
  if (getPiece(fromRow, fromColumn)->getColor() == Color::Black)
  {
    blackPieces.remove(getPiece(fromRow, fromColumn));
  }
  else
  {
    whitePieces.remove(getPiece(fromRow, fromColumn));
  }

  // removes piece from new location if occupied
  if (isOccupied(toRow, toColumn))
  {
    removeChessPiece(toRow, toColumn);
  }

  // moves piece to new location
  createChessPiece(getPiece(fromRow, fromColumn)->getColor(), getPiece(fromRow, fromColumn)->getType(), toRow, toColumn);
  removeChessPiece(fromRow, fromColumn);

  //readd to list
  if (getPiece(toRow, toColumn)->getColor() == Color::Black)
  {
    blackPieces.emplace_back(getPiece(toRow, toColumn));
  }
  else
  {
    whitePieces.emplace_back(getPiece(toRow, toColumn));
  }

  //readd king ptr
  if (getPiece(toRow, toColumn)->getType() == Type::King)
  {
    if (getPiece(toRow, toColumn)->getColor() == Color::White)
    {
      whiteKing = (KingPiece*)getPiece(toRow, toColumn);
    }
    else
    {
      blackKing = (KingPiece*)getPiece(toRow, toColumn);
    }
  }

  return;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn)
{
   printf("From %d %d to %d %d\n", fromRow, fromColumn, toRow, toColumn);
  //  checks if move is valid
  if (!isValidMove(fromRow, fromColumn, toRow, toColumn))
  {
    return false;
  }

  // forces move
  if (turn != getPiece(fromRow, fromColumn)->getColor())
  {
    // printf("FALSE TURN\n");
    return false;
  }

  forceMove(fromRow, fromColumn, toRow, toColumn);
  turn = (turn == Color::White) ? Color::Black : Color::White;
  // std::cout<<"TURN "<<

  // returns true if move is valid
  return true;
}

bool ChessBoard::isPieceUnderThreat(int row, int column)
{
  // checks if piece is under threat
  // printf("UNDER THREAT SCAN\n");
  // printf("ROW %d COL %d\n", row,column);
  // checks if piece is null
  if (getPiece(row, column) == nullptr)
  {
    return false;
  }

  // checks if piece is black
  Color piececolor = getPiece(row, column)->getColor();
  printf("PIECE COLOR %d\n", piececolor);
  if (piececolor == Color::Black)
  {
     printf("BLACK PIECE CHECK\n");
    //  checks if piece is under threat by white
    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
    {

      if ((*it)->canMoveToLocation(row, column))
      {
        printf("Piece at %d %d is under threat by %d %d\n", row, column, (*it)->getRow(), (*it)->getColumn());
        return true;
      }
    }
  }
  // checks if piece is white
  else
  {
     printf("WHITE PIECE CHECK\n");
    //  checks if piece is under threat by black
    printf("LIST SIZE %d\n", blackPieces.size());
    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
    {
      
      if ((*it)->canMoveToLocation(row, column))
      {
        printf("Piece at %d %d is under threat by %d %d\n", row, column, (*it)->getRow(), (*it)->getColumn());
        return true;
      }
    }
  }
  // returns false if piece is not under threat
  return false;
}

bool ChessBoard::isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
  // finds color of frompiece
  Color fromColor = getPiece(fromRow, fromColumn)->getColor();
  printf("FROM COLOR %d from loc %d %d to loc %d %d\n", fromColor, fromRow, fromColumn, toRow, toColumn);
  // checks if king of same color exists
  if (fromColor == Color::Black)
  {
    if (blackKing == nullptr)
    {
      printf("BLACK KING NULL\n");
      return false;
    }
  }
  else
  {
    if (whiteKing == nullptr)
    {
      printf("WHITE KING NULL\n");
      return false;
    }
  }

  // we know king exists
  // store king position
  int kingRow = (fromColor == Color::Black) ? blackKing->getRow() : whiteKing->getRow();
  int kingCol = (fromColor == Color::Black) ? blackKing->getColumn() : whiteKing->getColumn();

  // checks if king is in from position
  if (kingRow == fromRow && kingCol == fromColumn)
  {
    kingRow = toRow;
    kingCol = toColumn;
  }

  // checks if king is safe after move
  printf("King is at %d %d with color: %d\n", kingRow, kingCol, fromColor);
  //iterate through all pieces of opposite color
  if (fromColor == Color::Black)
  {
    printf("BLACK KING CHECK2\n");
    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
    {
      if ((*it)->canMoveToLocation(kingRow, kingCol))
      {
        printf("King is under threat by %d %d\n", (*it)->getRow(), (*it)->getColumn());
        return false;
      }
    }
  }
  else
  {
    printf("WHITE KING CHECK2\n");
    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
    {
      if ((*it)->canMoveToLocation(kingRow, kingCol))
      {
        printf("King is under threat by %d %d\n", (*it)->getRow(), (*it)->getColumn());
        return false;
      }
    }
  }
  printf("KING IS SAFE\n");
  return true;
  /*
  // checks if king is safe after move
  int row = 0;
  int column = 0;
  if(getPiece(fromRow,fromColumn)->getColor() == Color::White){
    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
    {
      if ((*it)->getType() == Type::King)
      {
        row = (*it)->getRow();
        column = (*it)->getColumn();
      }
    }
  }
  else{
    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
    {
      if ((*it)->getType() == Type::King)
      {
        row = (*it)->getRow();
        column = (*it)->getColumn();
      }
    }
  }

  for(int i = fromRow; i < fromColumn; i++){
    for(int j = fromColumn; j < toColumn; j++){
      if(i == row || j == column){
        return false;
      }
    }
  }
  if (getPiece(row, column)->getColor() == Color::Black)
  {
    //printf("BLACK PIECE CHECK\n");
    // checks if piece is under threat by white
    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
    {

        if ((*it)->canMoveToLocation(row, column))
        {
          return false;
        }

    }
  }
  else
  {
    //printf("WHITE PIECE CHECK\n");
    // checks if piece is under threat by black
    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
    {
      if ((*it)->canMoveToLocation(row, column))
      {
        return false;
      }
    }
  }
  */
}

std::ostringstream ChessBoard::displayBoard()
{
  std::ostringstream outputString;
  // printf("PRINTING DISPLAY BOARD... (Board %d %d)\n", numCols, numRows);
  //  top scale
  outputString << "  ";
  for (int i = 0; i < numCols; i++)
  {
    outputString << i;
  }
  outputString << std::endl
               << "  ";
  // top border
  for (int i = 0; i < numCols; i++)
  {
    outputString << "-";
  }
  outputString << std::endl;

  for (int row = 0; row < numRows; row++)
  {
    outputString << row << "|";
    for (int column = 0; column < numCols; column++)
    {
      ChessPiece *piece = board.at(row).at(column);
      outputString << (piece == nullptr ? " " : piece->toString());
    }
    outputString << "|" << std::endl;
  }

  // bottom border
  outputString << "  ";
  for (int i = 0; i < numCols; i++)
  {
    outputString << "-";
  }
  outputString << std::endl
               << std::endl;

  return outputString;
}