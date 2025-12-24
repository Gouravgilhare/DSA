class Solution {
    private:
    void dfs(int sr, int sc, vector<vector<char>>&grid, vector<vector<int>>&vis){
        int n =grid.size();
        int m = grid[0].size();
    
        vis[sr][sc]=1;
        int dx[4] ={1,-1,0,0};
        int dy[4] ={0,0,1,-1};
        
        
        for(int i= 0; i< 4; i++ ){
            int nr = sr +dx[i];
            int nc = sc +dy[i];
            if(nr>= 0 && nr<n && nc >=0 && nc <m && !vis[nr][nc] && grid[nr][nc] =='O'){
                dfs(nr,nc,grid,vis);
            }
        }
        
        
    }
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n =grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        for(int j = 0 ; j< m ; j++){
            
            if(!vis[0][j] && grid[0][j]=='O')
                dfs(0,j,grid,vis);
                
            if(!vis[n-1][j] && grid[n-1][j]=='O')
                dfs(n-1,j,grid,vis);
                
        }
    
        for(int j = 0 ; j< n; j++){
            
            if(!vis[j][0] && grid[j][0]=='O')
                dfs(j,0,grid,vis);
                
            if(!vis[j][m-1] && grid[j][m-1]=='O')
                dfs(j,m-1,grid,vis);
                
        }
        
        
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(!vis[i][j] && grid[i][j] == 'O'){
                    grid[i][j] = 'X';
                    // vis[i][j]=1;
                }
            }
        }
        
    }
};