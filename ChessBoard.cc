#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol) {
}

ChessBoard::ChessBoard(ChessBoard& other) {
}

ChessBoard::~ChessBoard() {
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
}

void ChessBoard::removeChessPiece(int row, int column) {
}

bool ChessBoard::isOccupiedWithColor(int row, int column, Color color) {
}

void ChessBoard::forceMove(int fromRow, int fromColumn, int toRow, int toColumn) {
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
}

bool ChessBoard::isKingSafeAfterMove(int fromRow, int fromColumn, int toRow, int toColumn) {
}

std::ostringstream ChessBoard::displayBoard() {
  std::ostringstream outputString;
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
