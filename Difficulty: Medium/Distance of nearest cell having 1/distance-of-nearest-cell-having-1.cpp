class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        vector<vector<int>>dist(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0 ; i< n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) {
                    vis[i][j] = 1;
                    // dist[i][j] = 0;
                    q.push({{i,j},0});
                }
            }
        }
        
        
        int dx[]= {1,-1,0,0};
        int dy[]= {0,0,1,-1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            dist[row][col]=step;
            
            for(int i= 0 ; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
                    q.push({{nr,nc},step+1});
                    vis[nr][nc]=1;
                }
            }
            
        }
        
        
        
        return dist;
    }
};