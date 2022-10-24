#include "ChessBoard.hh"
#include "RookPiece.hh"

using Student::ChessPiece;
using Student::RookPiece;


bool RookPiece::isValidColumnMove(int toColumn)
{
    //step 1
    return true;
}

bool RookPiece::isValidRowMove(int toRow)
{
    //step 1
    return true;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    //step 2
    return true;
}

const char* RookPiece::toString()
{
    //step 1
    if(ChessPiece::getColor() == Color::Black)
    {
    return "\u265C";
    }
    return "\u2656";
}


