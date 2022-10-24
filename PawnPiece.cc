#include "ChessBoard.hh"
#include "PawnPiece.hh"

using Student::ChessPiece;
using Student::PawnPiece;


bool PawnPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    //step 1
    return true;
}

bool PawnPiece::isValidRowMove(int toRow)
{
    //step 1
    return true;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
{
    //step 2
    return true;
}

const char* PawnPiece::toString()
{
    //step 1
    if(ChessPiece::getColor() == Color::Black)
    {
    return "\u265F";
    }
    return "\u2659";
}


