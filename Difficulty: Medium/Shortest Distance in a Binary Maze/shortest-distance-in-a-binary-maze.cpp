// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source == destination) return 0;
        if(grid[source.first][source.second] == 0 ||
           grid[destination.first][destination.second] == 0)
            return -1;

        queue<pair<int,pair<int, int>>> q;
        int n = grid.size();
        int  m = grid[0].size();
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        int dr []  = {1,-1,0,0};
        int dc []  = {0,0,1,-1};
        
        while(!q.empty()){
            int dis = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            
            for(int i = 0 ; i< 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
            
                if(nr >=0 && nr < n
                && nc >= 0 && nc < m
                && grid[nr][nc] == 1 
                && dis +1 < dist[nr][nc]){
                    dist[nr][nc] = dis + 1;
                    if(nr == destination.first && nc == destination.second) 
                        return dis+ 1;
                    q.push({dis+1, {nr,nc}});
                }
                
            }
            
        }
        return -1;
    }
};
