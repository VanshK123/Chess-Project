#include "ChessBoard.hh"
#include "ChessPiece.hh"
//#include "PawnPiece.hh"
//#include "RookPiece.hh"
//#include "BishopPiece.hh"
//#include "KingPiece.hh"

using Student::ChessPiece;

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

/*

BishopPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    return true;
}

BishopPiece::BishopPiece(ChessBoard& board, Color color, int startRow, int startColumn)
{

}

BishopPiece::canMoveToLocation(int toRow, int toColumn)
{

}

BishopPiece::ToString()
{

}
*/

