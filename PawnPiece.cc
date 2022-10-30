#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "ChessBoard.hh"

using Student::ChessPiece;
using Student::PawnPiece;
using Student::ChessBoard;

static int sign(int x);
static int absolute(int x);
static int sign(int x) {
    return (x > 0) - (x < 0);
}
static int absolute(int x)
{
    return x * sign(x);
}

bool PawnPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    //step 1
    int row = getRow();
    int col = getColumn();
    Color PieceColor = getColor();

    int ymove = toRow - row;
    int xmove = toColumn - col;

    //check if move is valid diagonal 

    if(absolute(xmove) != absolute(ymove)){
        return false;
    }

    //check if move is greater then 1
    if(absolute(xmove) > 1 || absolute(ymove) > 1)
    {
        return false;
    }

    //check if color matches direction
    if(PieceColor == Color::Black)
    {
        if(ymove <= 0)
        {
            return false;
        }
    }
    else
    {
        if(ymove >= 0)
        {
            return false;
        }
    }

    //check if diagonal has enemy piece
    Color colofotherpiece = PieceColor == Color::Black ? Color::White : Color::Black;
    if(!mBoard.isOccupiedWithColor(toRow, toColumn, colofotherpiece)){
        return false;
    }

    return true;

}

bool PawnPiece::isValidRowMove(int toRow)
{
    //step 1
    int row = getRow();
    int ymove = toRow - row;
    bool isAtStart = false;
    //check if pawn is at start
    if(getColor() == Color::Black)
    {
        if(row == 1)
        {
            isAtStart = true;
        }
    }
    else
    {
        if(row == (mBoard.getNumRows() - 2))
        {
            isAtStart = true;
        }
    }

    //check if move is 1 or 2 based on if is at start
    if(isAtStart)
    {
        if(absolute(ymove) > 2)
        {
            //printf("[PAWN] ymove is greater then 2");
            return false;
        }
    }
    else
    {
        if(absolute(ymove) > 1)
        {
            //printf("[PAWN] ymove is greater then 2");
            return false;
        }
    }

    //check direction of move
    //check if color matches direction
    if(getColor() == Color::Black)
    {
        if(ymove <= 0)
        {
            //printf("[PAWN] black piece wrong dir");
            return false;
        }
    }
    else
    {
        if(ymove >= 0)
        {
            //printf("[PAWN] white piece wrong dir");
            return false;
        }
    }


    //check if is blocked when moving 2
    if(isAtStart && absolute(ymove) == 2)
    {
        if(mBoard.isOccupied(row + sign(ymove), getColumn()))
        {
            //printf("[PAWN] blocking move ");
            return false;

        }
    }

    return true;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn)
{
   
    //step 2
    int row = mBoard.getNumRows();
    int col = mBoard.getNumCols();
    int xmove = toColumn - getColumn();
    int ymove = toRow - getRow();
    Color temp = getColor();
    if(temp == Color::Black){
        //printf("Black rook Move");
    }
    else{
        //printf("White Rook move");
    }
 //printf("[PAWN] Checking moves of pawn from %d %d to %d %d moving %d %d", getRow(), getColumn(), toRow, toColumn, ymove, xmove);
    //check null
    if(toRow > row || toColumn > col || toRow < 0 || toColumn < 0){
        //printf("[PAWN] Fails board bounds");
        return false;
    }
    //printf("[PAWN] Passes board bounds");

    //check move with same col
    if(mBoard.isOccupiedWithColor(toRow, toColumn, getColor())){
        //printf("[PAWN] Fails same color check");
        return false;
    }
    //printf("[PAWN] Passes same color check");

    //check valid diagonal
    if(xmove != 0)
    {
if(!isValidDiagonalMove(toRow,toColumn)){
        //printf("[PAWN] Fails diagonal check");
        return false;
    }
    //printf("[PAWN] Passes diagonal check");
    }
    
    if(ymove != 0)
    {
    //check valid row
    if(!isValidRowMove(toRow)){
        //printf("[PAWN] Fails Row check");
        return false;
    }
    //printf("[PAWN] Passes Row check");
    }

    //printf("[PAWN] Passes all move checks\n");
    Color colofotherpiece = getColor() == Color::Black ? Color::White : Color::Black;
    
    if(absolute(getRow()-toRow) <= 2 && getColumn() == toColumn){
        if(mBoard.isOccupiedWithColor(toRow,toColumn,colofotherpiece)){
            return false;
        }
    }
    
    return true;
}

PawnPiece::PawnPiece(ChessBoard& board, Color color, int startRow, int startColumn): ChessPiece(board, color, startRow, startColumn){
    mType = Pawn;
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


