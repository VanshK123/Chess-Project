#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include "BishopPiece.hh"
#include<fstream>
#include<string>
#include<iostream>

using Student::BishopPiece;
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

bool BishopPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    // step 1
    int col = getColumn();
    int row = getRow();
    int yMove = toRow - row;
    int xMove = toColumn - col;
    //printf("%d  %d %d %d %d %d\n", yMove, xMove, absolute(yMove), absolute(xMove), sign(yMove), sign(xMove));
    // check is valid diagonal move
    if (absolute(xMove) != absolute(yMove))
    {
        //printf("[BISHOP] xmove not equal ymove FAILED");
        return false;
    }

    // check if nonblocking
    for (int i = 1; i < absolute(yMove); i++)
    {
        // check if diagonal has enemy piece
        //Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
        //printf("row: %d col: %d i: %d, %d %d, %d\n", row, col, i, row+(sign(yMove) * i), col+(sign(xMove) * i), mBoard.isOccupiedWithColor(row + (sign(yMove) * i), col + (sign(xMove) * i), colofotherpiece));
        if (mBoard.isOccupied(row + (sign(yMove) * i), col + (sign(xMove) * i)))
        {
            //printf("[BISHOP] blocking\n");
            return false;
        }
    }
    //printf("[BISHOP] not blocked\n");
    return true;
}

BishopPiece::BishopPiece(ChessBoard &board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn)
{
    mType = Bishop;
}

bool BishopPiece::canMoveToLocation(int toRow, int toColumn)
{
    // step 2

    int row = mBoard.getNumRows();
    int col = mBoard.getNumCols();
       Color temp = getColor();
    if(temp == Color::Black){
        //printf("Black bishop Move\n");
    }
    else{
        //printf("White bishop move\n");
    }
    //int ymove = toRow - getRow();
    //int xmove = toColumn - getColumn();
    //printf("BISHOP TEST MOVE, %d %d to %d %d moving %d, %d\n", getRow(), getColumn(), toRow, toColumn, ymove, xmove);
    if (toRow > row || toColumn > col || toRow < 0 || toColumn < 0)
    {
        //printf("[BISHOP] OUT OF BOUNDS FAILED\n");
        return false;
    }
    //printf("[BISHOP] OUT OF BOUNDS PASSED\n");

    if (mBoard.isOccupiedWithColor(toRow, toColumn, getColor()))
    {
        return false;
    }
    if (!isValidDiagonalMove(toRow, toColumn))
    {
        //printf("BISHOP INVALID DIAGONAL MOVE\n");
        return false;
    }
    //printf("BISHOP CANMOVE\n");
    return true;
}

const char *BishopPiece::toString()
{
    // step 1
    if (ChessPiece::getColor() == Color::Black)
    {
        return "\u265D";
    }
    return "\u2657";
}