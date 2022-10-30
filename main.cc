#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

#include <iostream>
#include <sstream>

int main() {
    /**
    Student::ChessBoard sBoard(8, 8);
    sBoard.createChessPiece(Black, Pawn, 1, 1);
    sBoard.createChessPiece(White, Pawn, 2, 0);
    sBoard.createChessPiece(White, Pawn, 6, 1);
    sBoard.createChessPiece(Black, Pawn, 5, 1);
    sBoard.createChessPiece(White, Pawn, 6, 0);
    std::cout <<  sBoard.displayBoard().str() << std::endl;
    //sBoard.isValidMove(0, 0, 5, 0);
    
    assert(sBoard.isValidMove(1, 1, 3, 1) == true);
    assert(sBoard.isValidMove(1, 1, 2, 1) == true);
    //printf("\033[0;32m");
    //printf("Black pawn move y 1-2\n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(1, 1, 4, 1) == false);
    assert(sBoard.isValidMove(1, 1, 5, 1) == false);

    assert(sBoard.isValidMove(1, 1, -1, 1) == false);
    assert(sBoard.isValidMove(1, 1,  3, 3) == false);
    //printf("\033[0;32m");
    //printf("Black pawn move invalid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(1, 1, 2, 2) == false);
    assert(sBoard.isValidMove(1, 1,  3, 0) == false);
    assert(sBoard.isValidMove(1, 1, 3, 2) == false);
    assert(sBoard.isValidMove(1, 1,  3, 3) == false);
    //printf("\033[0;32m");
    //printf("Black pawn diagonal invalid \n");
    //printf("\033[0m");


    assert(sBoard.isValidMove(6, 0, 4, 0) == true);
    assert(sBoard.isValidMove(6, 0, 5, 0) == true);
    //printf("\033[0;32m");
    //printf("White pawn move y 1-2\n");
    //printf("\033[0m");

    //too far
    assert(sBoard.isValidMove(6, 0, 3, 0) == false);
    assert(sBoard.isValidMove(6, 0, 2, 0) == false);
    assert(sBoard.isValidMove(6, 0, -1, 0) == false);
    assert(sBoard.isValidMove(6, 0, 6, 3) == false);
    //printf("\033[0;32m");
    //printf("White pawn move invalid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(6, 0, 5, 1) == true);
    assert(sBoard.isValidMove(6, 0,  5, 2) == false);
    assert(sBoard.isValidMove(6, 0, 4, 1) == false);
    assert(sBoard.isValidMove(6, 0,  4, 2) == false);
    //printf("\033[0;32m");
    //printf("White pawn diagonal invalid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(1, 1,  2, 0) == true);
    //printf("\033[0;32m");
    //printf("Black pawn diagonal valid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(6, 0,  5, 1) == true);
    //printf("\033[0;32m");
    //printf("White pawn diagonal valid \n");
    //printf("\033[0m");

    sBoard.createChessPiece(Black, Pawn, 2, 1);
    sBoard.createChessPiece(White, Pawn, 5, 0);
    assert(sBoard.isValidMove(1, 1,  2, 1) == false);
    //printf("\033[0;32m");
    //printf("Black pawn blocking valid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(6, 0,  5, 0) == false);
    //printf("\033[0;32m");
    //printf("White pawn blocking valid \n");
    //printf("\033[0m");

    sBoard.removeChessPiece(2, 2);
    assert(sBoard.isOccupied(2, 2) == false);
    sBoard.removeChessPiece(2, 1);
    assert(sBoard.isOccupied(2, 1) == false);
    sBoard.removeChessPiece(1, 1);
    assert(sBoard.isOccupied(1, 1) == false);
    sBoard.removeChessPiece(2, 1);
    assert(sBoard.isOccupied(2, 1) == false);
    sBoard.removeChessPiece(2, 0);
    assert(sBoard.isOccupied(2, 0) == false);
    //printf("\033[0;32m");
    //printf("Black pawn delete valid \n");
    //printf("\033[0m");

     sBoard.removeChessPiece(5, 0);
    assert(sBoard.isOccupied(5, 0) == false);
    sBoard.removeChessPiece(5, 1);
    assert(sBoard.isOccupied(5, 1) == false);
    sBoard.removeChessPiece(6, 1);
    assert(sBoard.isOccupied(6, 1) == false);
    sBoard.removeChessPiece(6, 0);
    assert(sBoard.isOccupied(6, 0) == false);
    //printf("\033[0;32m");
    //printf("White pawn delete valid \n");
    //printf("\033[0m");
    std::cout <<  sBoard.displayBoard().str() << std::endl;

    sBoard.createChessPiece(Black, Bishop, 3, 3);
    sBoard.createChessPiece(Black, Bishop, 1, 1);
    sBoard.createChessPiece(White, Bishop, 5, 5);
    assert(sBoard.isOccupied(1, 1) == true);
    assert(sBoard.isOccupied(3, 3) == true);
    assert(sBoard.isOccupied(5, 5) == true);
    //printf("\033[0;32m");
    //printf("Bishop Create valid \n");
    //printf("\033[0m");
    std::cout <<  sBoard.displayBoard().str() << std::endl;



    assert(sBoard.isValidMove(3, 3,  4, 4) == true);
    assert(sBoard.isValidMove(3, 3,  2, 2) == true);
    assert(sBoard.isValidMove(3, 3,  4, 2) == true);
    assert(sBoard.isValidMove(3, 3,  2, 4) == true);
    //printf("\033[0;32m");
    //printf("Black Bishop 1-move valid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(3, 3,  5, 5) == true);
    assert(sBoard.isValidMove(3, 3,  1, 1) == false);
    assert(sBoard.isValidMove(3, 3,  5, 1) == true);
    assert(sBoard.isValidMove(3, 3,  1, 5) == true);
    //printf("\033[0;32m");
    //printf("Black Bishop move valid \n");
    //printf("\033[0m");

assert(sBoard.isValidMove(5, 5,  6, 6) == true);
    assert(sBoard.isValidMove(5, 5,  4, 4) == true);
    assert(sBoard.isValidMove(5, 5,  6, 4) == true);
    assert(sBoard.isValidMove(5, 5,  4, 6) == true);
    //printf("\033[0;32m");
    //printf("White Bishop 1-move valid \n");
    //printf("\033[0m");

    assert(sBoard.isValidMove(5, 5,  7, 7) == true);
    assert(sBoard.isValidMove(5, 5,  2, 2) == false);
    assert(sBoard.isValidMove(5, 5,  7, 3) == true);
    assert(sBoard.isValidMove(5, 5,  3, 7) == true);
    //printf("\033[0;32m");
    //printf("White Bishop move valid \n");
    //printf("\033[0m");

assert(sBoard.isValidMove(3,3,9,9) == false);
assert(sBoard.isValidMove(5,5,9,9) == false);
assert(sBoard.isValidMove(3,3,-1,-1) == false);
assert(sBoard.isValidMove(5,5,-1,-1) == false);
    //printf("\033[0;32m");
    //printf("White and Black Bishop move valid \n");
    //printf("\033[0m");

assert(sBoard.isValidMove(3,3,7,7) == false);
assert(sBoard.isValidMove(5,5,2,2) == false);
    //printf("\033[0;32m");
    //printf("White and Black Bishop Not Blocked \n");
    //printf("\033[0m");
    sBoard.removeChessPiece(3, 3);
    sBoard.removeChessPiece(5, 5);
    sBoard.removeChessPiece(1, 1);
    assert(sBoard.isOccupied(1, 1) == false);
    assert(sBoard.isOccupied(3, 3) == false);
    assert(sBoard.isOccupied(5, 5) == false);
    //printf("\033[0;32m");
    //printf("Bishop delete valid \n");
    //printf("\033[0m");
    std::cout <<  sBoard.displayBoard().str() << std::endl;
   
 
  sBoard.createChessPiece(White, Rook, 0, 0);
  sBoard.createChessPiece(Black, Rook, 0, 3);

  // rook can make legal move to the right
  assert(sBoard.isValidMove(0, 0, 0, 2));

  // rook cannot jump another piece
  assert(!sBoard.isValidMove(0, 0, 0, 5));

  // rook cannot jump another piece OR move to an invalid place
  assert(!sBoard.isValidMove(0, 0, 0, 7));

  // rook can capture another piece
  assert(sBoard.isValidMove(0, 0, 0, 3));

  sBoard.createChessPiece(White, Rook, 2, 3);
  sBoard.createChessPiece(Black, Rook, 1, 3);

  // rook can make legal move to the right
  assert(sBoard.isValidMove(0, 0, 2, 4) == false);

  // rook cannot jump another piece
  assert(!sBoard.isValidMove(0, 0, 0, 4));

  // rook cannot jump another piece OR move to an invalid place
  assert(!sBoard.isValidMove(0, 0, -1, 3));

  // rook can capture another piece
  assert(!sBoard.isValidMove(0, 0, 1, 3));

std::cout <<  sBoard.displayBoard().str() << std::endl;
sBoard.removeChessPiece(0, 3);
    sBoard.removeChessPiece(0, 0);
    sBoard.removeChessPiece(1, 3);
    sBoard.removeChessPiece(2, 3);
std::cout <<  sBoard.displayBoard().str() << std::endl;
    return EXIT_SUCCESS;
    */
   Student::ChessBoard sBoard(4, 4);
   sBoard.createChessPiece(White,Rook,0,2);
   sBoard.createChessPiece(White,Rook,2,2);
   assert(!sBoard.isValidMove(0,2,3,2));
}
