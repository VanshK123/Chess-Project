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

//helper function for sign
static int sign(int x)
{
    return (x > 0) - (x < 0);
}

//helper function for absolute
static int absolute(int x)
{
    return x * sign(x);
}

//constructor
KingPiece::KingPiece(ChessBoard& board, Color color, int startRow, int startColumn): ChessPiece(board, color, startRow, startColumn)
{
    mType = King;
}

//check if can move to given location
bool KingPiece::canMoveToLocation(int toRow, int toColumn)
{
    int xMove = toColumn - getColumn();
    int yMove = toRow - getRow();

    //check if move is greater than 1
    if (absolute(xMove) > 1 || absolute(yMove) > 1)
    {
        return false;
    }

    //check if move is occupied by own piece
    if (mBoard.isOccupied(toRow, toColumn))
    {
        if (mBoard.getPiece(toRow, toColumn)->getColor() == getColor())
        {
            return false;
        }
    }

    //check if move is out of bounds
    if (toRow > mBoard.getNumRows() || toColumn > mBoard.getNumCols() || toRow < 0 || toColumn < 0)
    {
        return false;
    }

    //redundant i think
    //if (mBoard.isOccupiedWithColor(toRow, toColumn, getColor()))
    //{
    //    return false;
    //}

    //check if move will put king in check
    if (!mBoard.isKingSafeAfterMove(getRow(), getColumn(), toRow, toColumn))
    {
        //printf("King is not safe after move\n");
        return false;
    }

    
    return true;
}

//return char representation of piece
const char* KingPiece::toString(){
    // step 1
    if (ChessPiece::getColor() == Color::Black)
    {
        return "\u265A";
    }
    return "\u2654";
}


