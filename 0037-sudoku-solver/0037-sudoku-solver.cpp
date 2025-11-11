class Solution {
public:

    bool isSafe( vector<vector<char>>&board, int row, int col,char c){
        
        for(int i = 0 ; i< 9 ; i++){
            if(board[row][i] == c)return false;
            if(board[i][col] == c)return false;

            int subRow = 3 * (row/3)+i/3;
            int subCol = 3*(col/3)+i%3;

            if(board[subRow][subCol]==c) return false;
        }

        return true;
    }

    bool sudoku(vector<vector<char>>& board, int cell = 0){
        if(cell == 81) return true;

        int row = cell /9;
        int col = cell %9;
    
        if(board[row][col]!='.')return sudoku(board,cell+1);

        for(char c='1' ;c<='9';c++ ){
            if(isSafe(board,row,col,c)){
                board[row][col]=c;
                if(sudoku(board,cell+1))return true;

                board[row][col]= '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        sudoku(board,0);
    }
};