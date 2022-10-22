#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

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

  //ChessPiece(ChessBoard& board, Color color, int row, int column);

  return;
}

void ChessBoard::removeChessPiece(int row, int column) {
  return;
}

bool ChessBoard::isOccupiedWithColor(int row, int column, Color color) {
  return true;
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn) {
  return;
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
  return true;
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
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
  printf("PRINTING DISPLAY BOARD... (Board %d %d)\n", numCols, numRows);
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
