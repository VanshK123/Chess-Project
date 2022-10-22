#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

#include <iostream>
#include <sstream>

int main() {
    printf("INI\n");
    Student::ChessBoard sBoard(8, 8);
    std::cout <<  sBoard.displayBoard().str() << std::endl;
    sBoard.createChessPiece(Black, Rook, 0, 0);
    assert(sBoard.isValidMove(0, 0, 2, 3) == false);
    assert(sBoard.isValidMove(0, 0, 5, 0) == true);

    return EXIT_SUCCESS;
}
