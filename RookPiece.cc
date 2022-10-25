#include "ChessBoard.hh"
#include "RookPiece.hh"

using Student::ChessPiece;
using Student::RookPiece;

/*
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
*/

bool RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    //step 2
    int row = mBoard.getNumRows();
    int col = mBoard.getNumCols();

    if(toRow > row || toColumn > col || toRow < 0 || toColumn < 0){
        printf("first if");
        return false;
    }
    if(mBoard.isOccupiedWithColor(toRow, toColumn, getColor())){
        printf("Second if");
        return false;
    }

    return true;
}

RookPiece::RookPiece(ChessBoard& board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn){

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


