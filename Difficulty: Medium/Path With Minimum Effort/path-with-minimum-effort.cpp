class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        priority_queue<
            pair<int, pair<int,int>>, 
            vector<pair<int, pair<int,int>>>, 
            greater<pair<int, pair<int,int>>>
        > pq;
        int n = mat.size(), m = mat[0].size();
        
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0,0}});
        int dr[] = {1,-1,0,0}; 
        int dc[] = {0,0,1,-1}; 
        
        while(!pq.empty()){
            int diff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            
            if(r == n-1 && c == m-1) return diff;
            
            for(int i = 0 ; i<4 ; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
            
                if(nr >=0 && nr < n && nc >= 0 && nc < m ){
                    int newEffort =max( abs( mat[nr][nc] - mat[r][c]), diff);
                    
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr,nc}});
                    }
                }
            }
            
        }
            return 0;
        
    }
};
