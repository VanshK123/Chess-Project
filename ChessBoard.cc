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

void printlist(std::list<ChessPiece*> const &list);
void printlist(std::list<ChessPiece*> const &list)
{
  
    for (auto const &i: list) {
        std::cout << "COL" << i->getColor() << "POS"<< i->getRow() << i->getColumn() << std::endl;
    }
}

ChessBoard::ChessBoard(int numRow, int numCol) {
  
board.resize(numRow, std::vector<ChessPiece*>(numCol, NULL));
numRows = numRow;
numCols = numCol;
return;
}

ChessBoard::ChessBoard(ChessBoard& other) {
}

ChessBoard::~ChessBoard() {
  //board.clear();
  for(int i = 0; i < numRows;i++){
    for(int j = 0; j<numRows;j++){
      delete board.at(i).at(j);
    }
  }

}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {

  
  if(startRow < 0 || startColumn < 0 || startRow >= numRows || startColumn >= numCols){
    return;
  }
  if(isOccupied(startRow,startColumn)){
    removeChessPiece(startRow,startColumn);
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
  
  if(piece->getColor() == Color::Black)
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
  //delete[] piece;
  return;
}

void ChessBoard::removeChessPiece(int row, int column) {
  if(board.at(row).at(column) != nullptr){
    delete board.at(row).at(column);
    board.at(row).at(column) = nullptr;
  }
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
  //printf("From %d %d to %d %d\n",fromRow,fromColumn,toRow,toColumn);
  if(toRow > numRows || toColumn > numCols || toRow < 0 || toColumn < 0 || fromRow > numRows || fromColumn > numCols || fromRow < 0 || fromColumn < 0){
    //printf("lammo xd\n");
    return false;
  }

  if(getPiece(fromRow,fromColumn) == nullptr){
    //printf("bruh\n");
    return false;
  }
  if(fromRow == toRow && fromColumn == toColumn){
    //printf("Bruh moment\n");
    return false;
  }

  
  if(getPiece(fromRow,fromColumn)->canMoveToLocation(toRow,toColumn)){
    printf("From %d %d to %d %d\n",fromRow,fromColumn,toRow,toColumn);
  }
  /*
  else{
    printf("FALSE ");
    printf("From %d %d to %d %d\n",fromRow,fromColumn,toRow,toColumn);
  }*/
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
