class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        Sudoku( board,0,0);
    }

    bool Sudoku( vector<vector<char>> &board, int row ,int col){

        if( row == 9) return true;

        if( col == 9 ) return Sudoku( board, row+1, 0 );

        if( board[row][col] != '.') return Sudoku( board, row, col+1);

        for(char k ='1'; k<='9';k++){
            if(isSafe(board, row, col, k)){
                board[row][col] = k;

                if( Sudoku( board, row,col+1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    bool isSafe( vector<vector<char>> &board, int row ,int col, char k){

        for( int i = 0; i<9; i++)
        if(board[row][i]== k) return false;


        for( int i = 0; i<9; i++)
        if(board[i][col]== k) return false;


        int s_row = (row/3)*3;
        int s_col = (col/3)*3;

        for(int i=s_row; i<s_row+3; i++)
        for(int j = s_col; j<s_col+3; j++)
            if(board[i][j]==k)
            return false;



            return true;
    }
};
