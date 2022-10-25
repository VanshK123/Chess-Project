#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "BishopPiece.hh"
#include <cstdlib>

using Student::ChessPiece;
using Student::BishopPiece;
using Student::ChessBoard;

bool BishopPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    //step 1
    int col = getColumn();
    int row = getRow();
    int xMove = toRow - row;
    int yMove = toColumn - col;
    if(xMove == 0 || yMove == 0 || abs(xMove) == abs(yMove)){
        return true;
    }
    return false;   
}

BishopPiece::BishopPiece(ChessBoard& board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn){

}



bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
{
    //step 2
    int row = mBoard.getNumRows();
    int col = mBoard.getNumCols();
    if(toRow > row || toColumn > col || toRow < 0 || toColumn < 0){
        return false;
    }
    if(mBoard.isOccupiedWithColor(toRow, toColumn, getColor())){
        return false;
    }
    if(!isValidDiagonalMove(toRow,toColumn)){
        return false;
    }
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


