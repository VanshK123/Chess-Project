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
    //printf("CREATING CHESS PIECE WITH ROW %d COL %d COLOR %d\n", row, column, color);
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
    ////printf("GETTING COL %d\n", mColumn);
    return mColumn;
}

int ChessPiece::getRow()
{
    ////printf("GETTING ROW %d\n", mRow);
    return mRow;
}

void ChessPiece::setPosition(int row, int column){
    mRow = row;
    mColumn = column;
}




 
