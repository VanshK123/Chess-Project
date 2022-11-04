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
  if (board.at(row).at(column) != nullptr)
  {
    if (getPiece(row,column)->getColor() == Color::Black)
    {
      blackPieces.remove(getPiece(row,column));
    }
    else
    {
      whitePieces.remove(getPiece(row,column));
    }
    delete board.at(row).at(column);
    board.at(row).at(column) = nullptr;
    
  }
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
  // printf("From %d %d to %d %d\n",fromRow,fromColumn,toRow,toColumn);
  if (toRow > numRows || toColumn > numCols || toRow < 0 || toColumn < 0 || fromRow > numRows || fromColumn > numCols || fromRow < 0 || fromColumn < 0)
  {
    // printf("lammo xd\n");
    return false;
  }

  if (getPiece(fromRow, fromColumn) == nullptr)
  {
    // printf("bruh\n");
    return false;
  }
  if (fromRow == toRow && fromColumn == toColumn)
  {
    // printf("Bruh moment\n");
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
  return (getPiece(fromRow, fromColumn)->canMoveToLocation(toRow, toColumn));
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn)
{

  // does nothing if not occupied
  if (!isOccupied(fromRow, fromColumn))
  {
    return;
  }

  // stores piece in temp variable
  //ChessPiece *temp = getPiece(fromRow, fromColumn);

  // removes piece from old location
  //removeChessPiece(fromRow, fromColumn);

  // removes piece from old location in list

  if (getPiece(fromRow,fromColumn)->getColor() == Color::Black)
  {
    blackPieces.remove(getPiece(fromRow,fromColumn));
  }
  else
  {
    whitePieces.remove(getPiece(fromRow,fromColumn));
  }

  // removes piece from new location if occupied
  if (isOccupied(toRow, toColumn))
  {
    /*
    if (getPiece(toRow,toColumn)->getColor() == Color::Black)
    {
      blackPieces.remove(getPiece(toRow,toColumn));
    }
    else
    {
      whitePieces.remove(getPiece(toRow,toColumn));
    }*/
    removeChessPiece(toRow, toColumn);
  }

  // moves piece to new location
  
  createChessPiece(getPiece(fromRow,fromColumn)->getColor(), getPiece(fromRow,fromColumn)->getType(), toRow, toColumn);
  removeChessPiece(fromRow, fromColumn);
  /*
  std::cout << "blackPieces" << std::endl;
  printlist(blackPieces);
  std::cout << "whitePieces" << std::endl;
  printlist(whitePieces);
  printf("\n");
  printf("BOARD \n");
  for (int i = 0; i < numRows; i++){
    for(int j = 0; j < numCols; j++)
    {
      if(board.at(i).at(j) != nullptr){
        
        std::cout << "COLOR " << getPiece(i,j)->getColor() << " POS " << getPiece(i,j)->getRow() << getPiece(i,j)->getColumn() << std::endl;
      }
    }
  }*/
  
  //std::cout<<displayBoard().str()<<std::endl;
  // deletes temp variable
  //delete temp;

  return;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn)
{
  //printf("From %d %d to %d %d\n", fromRow, fromColumn, toRow, toColumn);
  // checks if move is valid
  if (!isValidMove(fromRow, fromColumn, toRow, toColumn))
  {
    return false;
  }

  // forces move
  if(turn != getPiece(fromRow,fromColumn)->getColor()){
   // printf("FALSE TURN\n");
    return false;
  }

  forceMove(fromRow, fromColumn, toRow, toColumn);
  turn = (turn == Color::White) ? Color::Black : Color::White;
  //std::cout<<"TURN "<<

  // returns true if move is valid
  return true;
}

bool ChessBoard::isPieceUnderThreat(int row, int column)
{
  // checks if piece is under threat
  //printf("UNDER THREAT SCAN\n");
  //printf("ROW %d COL %d\n", row,column);
  // checks if piece is null
  if (getPiece(row, column) == nullptr)
  {
    return false;
  }

  // checks if piece is black
  if (getPiece(row, column)->getColor() == Color::Black)
  {
    //printf("BLACK PIECE CHECK\n");
    // checks if piece is under threat by white
    for (auto it = whitePieces.begin(); it != whitePieces.end(); ++it)
    {

        if ((*it)->canMoveToLocation(row, column))
        {
          return true;
        }
      
    }
  }
  // checks if piece is white
  else
  {
    //printf("WHITE PIECE CHECK\n");
    // checks if piece is under threat by black
    for (auto it = blackPieces.begin(); it != blackPieces.end(); ++it)
    {
      if ((*it)->canMoveToLocation(row, column))
      {
        return true;
      }
    }
  }
  // returns false if piece is not under threat
  return false;
}

bool ChessBoard::isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn)
{
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
  return true;
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