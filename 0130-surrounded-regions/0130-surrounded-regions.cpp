class Solution {
public:
    void dfs(int row, int col , vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        if(row<0 || row >=n || col < 0 || col>=m )return ;

        if(board[row][col]!='O' ) return ;

        board[row][col] = '#';


        int dx[] = {-1,1, 0,0};
        int dy[] = {0,0,-1,1};

        for(int i = 0 ; i< 4 ; i++){
            int nr = dx[i] + row;
            int nc  = dy[i] + col;

            dfs(nr,nc,board);
        }

        return ;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i< n ; i++){
            for(int j =0 ; j< m ; j++){

                if(((i==0 || i == n-1) || (j==0 || j == m-1)) && board[i][j]=='O' )
                {
                    dfs(i,j,board);
                }

            }
        }

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < m  ; j++){

                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};