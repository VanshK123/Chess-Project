#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
//#include "KingPiece.hh"

using Student::ChessPiece;
using Student::BishopPiece;


ChessPiece::ChessPiece(ChessBoard& board, Color color, int row, int column) : mBoard(board)
{
    mColor = color;
    mRow = row;
    mColumn = column;
    mColor = color;
    return;
}

Color ChessPiece::getColor()
{
    return mColor;
}

Type ChessPiece::getType()
{
    return mType;
}

int ChessPiece::getColumn()
{
    return mColumn;
}

int ChessPiece::getRow()
{
    return mRow;
}

void ChessPiece::setPosition(int row, int column){
    mRow = row;
    mColumn = column;
}




 
