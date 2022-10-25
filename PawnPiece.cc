#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "ChessBoard.hh"

using Student::ChessPiece;
using Student::PawnPiece;
using Student::ChessBoard;


bool PawnPiece::isValidDiagonalMove(int toRow, int toColumn)
{
    //step 1
    int row = getRow();
    int col = getColumn();
    Color temp = getColor();

    if(getColor() == Color::Black){
        temp = Color::White;
    }
    else{
        temp = Color::Black;
    }
    
    if(getColor() == Color::Black){
        if(toRow > row){
            if(toRow - row == 1 && abs(toColumn - col) == 1){
                if(mBoard.isOccupiedWithColor(toRow, toColumn, temp)){
                    return true;
                }
            }
        }
     
    }

    if(getColor() == Color::White){
        if(toRow < row){
            if(abs(toRow - row) == 1 && abs(toColumn - col) == 1){
                if(mBoard.isOccupiedWithColor(toRow, toColumn, temp)){
                    return true;
                }
            }
        }
     
    }
    

    return false;
}

bool PawnPiece::isValidRowMove(int toRow)
{
    //step 1
    int row = getRow();
    int Boardrow = mBoard.getNumRows();
    if(getColor() == Color::Black){
        if(toRow < row){
            return false;
        }
        if(row != 1){
            return false;
        }
    }

    if(getColor() == Color::White){
        if(toRow > row){
            return false;
        }
        if(row != Boardrow - 2){
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

    if(toRow > row || toColumn > col || toRow < 0 || toColumn < 0){
        return false;
    }
    if(mBoard.isOccupiedWithColor(toRow, toColumn, getColor())){
        return false;
    }
    if(!isValidDiagonalMove(toRow,toColumn)){
        return false;
    }
    
    int curRow = getRow();
    int curCol = getColumn();


    if(isValidRowMove(toRow) && abs(toColumn - curCol) <= 2){
        return true;
    }
    else if(toRow - curRow == 1){
        return true;
    }
    
    return false;
}

PawnPiece::PawnPiece(ChessBoard& board, Color color, int startRow, int startColumn): ChessPiece(board, color, startRow, startColumn){

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


