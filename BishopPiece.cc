#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "BishopPiece.hh"

using Student::ChessPiece;
using Student::BishopPiece;

bool BishopPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    //step 1
    return true;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
{
    //step 2
    return true;
}

const char* BishopPiece::toString()
{
    //step 1
    if(ChessPiece::getColor() == Color::Black)
    {
    return "\u265D";
    }
    return "\u2657";
}


