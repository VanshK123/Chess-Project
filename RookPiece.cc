#include "ChessBoard.hh"
#include "RookPiece.hh"

using Student::ChessPiece;
using Student::RookPiece;

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

bool RookPiece::isValidColumnMove(int toColumn)
{
    // step 1
    int col = getColumn();
    int xMove = toColumn - col;
    
    for (int i = 1; i < absolute(xMove); i++)
    {
        //Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
        if (mBoard.isOccupied(getRow(), col + (sign(xMove) * i)))
        {
            //printf("[ROOK] row blocking FAILED\n");
            return false;
        }
    }
    /*
    for (int i = getColumn(); i < toColumn; i++)
    {
        Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
        if (mBoard.isOccupied(getRow(), i))
        {
             //printf("Col %d\n",i);
            //printf("[ROOK] row blocking FAILED\n");
            return false;
        }
    }
    */
    //printf("[ROOK] row blocking passed\n");
    return true;
}


bool RookPiece::isValidRowMove(int toRow)
{
    // step 1
    int row = getRow();
    int yMove = toRow - row;
    //printf("Ymove %d\n",yMove);
    for (int i = 1; i < absolute(yMove); i++)
    {
       // Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
        //printf("ROW %d\n",(row + (sign(yMove) * i)));
        if (mBoard.isOccupied(row + (sign(yMove) * i), getColumn()))
        {
            
            //printf("[ROOK] row blocking FAILED\n");
            return false;
        }
    }
    
    /*
    if(getRow() < toRow){
        for (int i = getRow(); i < toRow-1; i++)
    {
        //printf("ROW %d\n",i);
        Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
        if (mBoard.isOccupied((i), getColumn()))
        {
            
            //printf("[ROOK] row blocking FAILED\n");
            return false;
        }
    }
    }
    else{
        for (int i = getRow(); i > toRow; i--)
    {
        //printf("ROW %d\n",i);
        Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
        if (mBoard.isOccupied((i), getColumn()))
        {
            
            //printf("[ROOK] row blocking FAILED\n");
            return false;
        }
    }
    }
    */
    //printf("[ROOK] row blocking passed\n");
    return true;
}

bool RookPiece::canMoveToLocation(int toRow, int toColumn)
{
    int row = mBoard.getNumRows();
    int col = mBoard.getNumCols();
    int ymove = toRow - getRow();
    int xmove = toColumn - getColumn();
    //printf("ROOK TEST MOVE, %d %d to %d %d moving %d, %d\n", getRow(), getColumn(), toRow, toColumn, ymove, xmove);
    if (toRow > row || toColumn > col || toRow < 0 || toColumn < 0)
    {
        //printf("[ROOK] OUT OF BOUNDS FAILED\n");
        return false;
    }
    //printf("[ROOK] OUT OF BOUNDS PASSED\n");

    if (mBoard.isOccupiedWithColor(toRow, toColumn, getColor()))
    {
        //printf("ROOK OCCUPIED WITH SAME COLOR\n");
        return false;
    }

    if(absolute(xmove) != 0 && absolute(ymove) != 0)
    {
        //printf("[ROOK] diagonal move failed\n");
        return false;
    }

    if (absolute(xmove) != 0)
    {
        if (!isValidColumnMove(toColumn))
        {
            //printf("[ROOK] Rook col move failed\n");
            return false;
        }
        //printf("[ROOK] Rook col move passed\n");
    }

    if (absolute(ymove) != 0)
    {
        if (!isValidRowMove(toRow))
        {
            //printf("[ROOK] Rook row move failed\n");
            return false;
        }
        //printf("[ROOK] Rook row move passed\n");
    }

    //printf("[ROOK] CANMOVE\n");

    return true;
}

RookPiece::RookPiece(ChessBoard &board, Color color, int startRow, int startColumn) : ChessPiece(board, color, startRow, startColumn)
{
    mType = Rook;
}

const char *RookPiece::toString()
{
    // step 1
    if (ChessPiece::getColor() == Color::Black)
    {
        return "\u265C";
    }
    return "\u2656";
}
