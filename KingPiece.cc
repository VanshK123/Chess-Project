#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include<fstream>
#include<string>
#include<iostream>

using Student::KingPiece;
using Student::ChessBoard;
using Student::ChessPiece;

static int sign(int x);
static int absolute(int x);
static int sign(int x)
{
    return (x > 0) - (x < 0);
}
static int absolute(int x)
{
    return x * sign(x);
}

KingPiece::KingPiece(ChessBoard& board, Color color, int startRow, int startColumn): ChessPiece(board, color, startRow, startColumn)
{
    mType = King;
}

bool KingPiece::canMoveToLocation(int toRow, int toColumn)
{
    int xMove = toColumn - getColumn();
    int yMove = toRow - getRow();
    if (absolute(xMove) > 1 || absolute(yMove) > 1)
    {
        return false;
    }
    if (mBoard.isOccupied(toRow, toColumn))
    {
        if (mBoard.getPiece(toRow, toColumn)->getColor() == getColor())
        {
            return false;
        }
    }
    if (toRow > mBoard.getNumRows() || toColumn > mBoard.getNumCols() || toRow < 0 || toColumn < 0)
    {
        return false;
    }

    if (mBoard.isOccupiedWithColor(toRow, toColumn, getColor()))
    {
        return false;
    }

    return true;
}

const char* KingPiece::toString(){
    // step 1
    if (ChessPiece::getColor() == Color::Black)
    {
        return "\u265A";
    }
    return "\u2654";
}
