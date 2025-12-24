// User function Template for C++
#define vi vector<int> 
#define vvi vector<vector<int>>

class Solution {
    private: 
        void dfs(int row, int col ,vvi &grid, vector<pair<int,int>>&vec, vvi&vis,int baseR, int baseC  ){
            int n =grid.size(), m = grid[0].size();
            vis[row][col]=1;
            vec.push_back({baseR-row, baseC -col});
            
            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};
        
            for(int i=0  ; i< 4; i++){
                int nr = row+dx[i];
                int nc = col +dy[i];
            
                if(nr>=0 && nr<n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc]==1){
                    dfs(nr,nc,grid,vec, vis,baseR, baseC);
                }
            }
            
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n =grid.size(), m = grid[0].size();
        set<vector<pair<int,int>>>st;
        vvi vis(n,vi(m,0));
        
        for(int i= 0 ; i < n ; i++){
            for(int j=0; j< m ; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,grid,vec,vis,i,j);
                    st.insert(vec);
                }
            }
        }
        
        
        return st.size();
        
    }
};
