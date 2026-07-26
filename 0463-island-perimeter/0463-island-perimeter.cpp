class Solution {
public:
    int dfs(int i , int  j, vector<vector<int>>&grid, vector<vector<int>>&vis){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0  || i >= n ||  j<0  || j>=m) return 1;
        if(grid[i][j]==0 ) return 1;
        if(vis[i][j]) return 0;
        
        vis[i][j] = 1;

        int dx[] = { -1, 1, 0,0};
        int dy[] = { 0, 0, 1,-1};
        
        int sum = 0;
        for(int k =0 ; k< 4; k++){
            int nr = dx[k] + i;
            int nc = dy[k] + j;
            sum+= dfs(nr, nc, grid, vis);
        }

        return sum;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m,0));

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j]==1)
                return  dfs(i,j ,grid, vis);
            }
        }
        return 0;
    }
};