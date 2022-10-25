#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

#include <iostream>
#include <sstream>

int main() {
    Student::ChessBoard sBoard(8, 8);
    sBoard.createChessPiece(Black, Rook, 0, 0);
    std::cout <<  sBoard.displayBoard().str() << std::endl;
    assert(sBoard.isValidMove(0, 0, 2, 3) == false);
    assert(sBoard.isValidMove(0, 0, 5, 0) == true);
    
    return EXIT_SUCCESS;
}
