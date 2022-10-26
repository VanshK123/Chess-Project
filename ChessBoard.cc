#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;
using Student::ChessPiece;

ChessBoard::ChessBoard(int numRow, int numCol) {
  
board.resize(numRow, std::vector<ChessPiece*>(numCol, NULL));
numRows = numRow;
numCols = numCol;
return;
}

ChessBoard::ChessBoard(ChessBoard& other) {
}

ChessBoard::~ChessBoard() {
  board.clear();
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {

  
  if(startRow < 0 || startColumn < 0 || startRow > numRows || startColumn > numCols){
    return;
  }

  ChessPiece *piece = NULL;
  //printf("TYPE: %d COLOR: %d\n", ty, col);

  if(ty == Type::Bishop){
     //printf("BISHOP row%d col: %d\n", startRow, startColumn);
    piece = new BishopPiece(*this,col,startRow,startColumn);
   
  }
  if(ty == Type::Pawn){
    //printf("Pawn row%d col: %d\n", startRow, startColumn);
    piece = new PawnPiece(*this,col,startRow,startColumn);
  }
  if(ty == Type::Rook){
    //printf("Rook row%d col: %d\n", startRow, startColumn);
    piece = new RookPiece(*this,col,startRow,startColumn);
  }
 

  if(isOccupied(startRow,startColumn)){
    delete board.at(startRow).at(startColumn);
    board.at(startRow).at(startColumn) = piece;
  }
  else{
    board.at(startRow).at(startColumn) = piece;
  }

  return;
}

void ChessBoard::removeChessPiece(int row, int column) {
  delete board.at(row).at(column);
  board.at(row).at(column) = nullptr;

  return;
}

bool ChessBoard::isOccupied(int row, int column){
  if(board.at(row).at(column) != nullptr){
    return true;
  }
  return false;
}

bool ChessBoard::isOccupiedWithColor(int row, int column, Color color) {
  
  if(board.at(row).at(column) != nullptr && color == getPiece(row,column)->getColor()){
    return true;
  }
  return false;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  
  if(getPiece(fromRow,fromColumn) == nullptr){
    //printf("bruh\n");
    return false;
  }

  return (getPiece(fromRow,fromColumn)->canMoveToLocation(toRow,toColumn));

    
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  return;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {



  return true;
}



bool ChessBoard::isPieceUnderThreat(int row, int column) {
  return true;
}

bool ChessBoard::isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  return true;
}

std::ostringstream ChessBoard::displayBoard() {
  std::ostringstream outputString;
  //printf("PRINTING DISPLAY BOARD... (Board %d %d)\n", numCols, numRows);
  // top scale
  outputString << "  ";
  for(int i = 0; i < numCols; i++) {
    outputString << i;
  }
  outputString << std::endl << "  ";
  // top border
  for(int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl;

  for(int row = 0; row < numRows; row++) {
    outputString << row << "|";
    for(int column = 0; column < numCols; column++) {
      ChessPiece* piece = board.at(row).at(column);
      outputString << (piece == nullptr ? " " : piece->toString());
    }
    outputString << "|" << std::endl;
  }

  // bottom border
  outputString << "  ";
  for(int i = 0; i < numCols; i++) {
    outputString << "-";
  }
  outputString << std::endl << std::endl;

  return outputString;
}
