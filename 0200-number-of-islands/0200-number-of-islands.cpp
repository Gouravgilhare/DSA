class Solution {
public:

    void  dfs (int row, int col, vector<vector<char>>& grid, vector<vector<bool>>&vis){
        int n = grid.size(), m = grid[0].size();

        if(row<0 || row >= n || col<0 || col>=m || grid[row][col]!='1' ) return ;
        if(vis[row][col])return ;

        vis[row][col]=true;
       
       
        dfs(row+1, col, grid,vis);
        dfs(row, col+1, grid,vis);
        dfs(row-1, col, grid,vis);
        dfs(row, col-1, grid,vis);
      


    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));

        int cnt=0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){

                dfs(i,j,grid,vis);
                cnt++;
                }
            }
        }

            return cnt;
    }   
};