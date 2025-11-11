class Solution {
public:

    bool isSafe( int n, vector<string>&board, int x , int y){

        for(int i = 0 ;i< x ; i++){
                if(board[i][y] == 'Q') return false;
        }
        for(int i = x-1, j =y-1   ;i >=0 && j>= 0 ; i--, j--){
                if(board[i][j] == 'Q') return false;
        }

        for(int i = x-1, j = y+1; i>= 0 && j<n; i--,j++)
                if(board[i][j] == 'Q') return false;

        return true;

    }

    void Nqueen(int n , vector<vector<string>>&ans, vector<string>&board, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col< n ; col++){
                if(isSafe(n,board,row,col )){
                board[row][col]='Q';
                Nqueen(n,ans,board,row+1);
                board[row][col]='.';
                }
        }

    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n, '.'));
 vector<vector<string>>ans;
        Nqueen(n,ans, board, 0);

        return ans;

    }
};