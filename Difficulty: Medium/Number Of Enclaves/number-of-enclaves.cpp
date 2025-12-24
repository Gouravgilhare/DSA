// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n, vector<int>(m,0));
        
        for(int i=0; i< n ; i++){
            for(int j =0 ; j< m ; j++){
                if(i==0 || j== 0 || i == n-1 || j == m-1){
                    if(!vis[i][j] && grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        
        
        int dx[]= {1,-1,0,0};
        int dy[]= {0,0,1,-1};
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i= 0 ;i<4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
            
                if(nr>=0 && nr <n && nc >=0 && nc <m &&!vis[nr][nc] && grid[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }    
        }
        
        int cnt = 0;
        for(int i = 0  ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j] && !vis[i][j])
                    cnt++;
            }
        }
        
        return cnt;
        
        
    }
};
