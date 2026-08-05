class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto &it : edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool> vis(V, false);
        int mst = 0 ;
        unordered_set<int>st;
        pq.push({0,0});
        
        
        while(!pq.empty()){
            auto [wt,u] = pq.top();
            pq.pop();
            
            if(!vis[u]){
                mst += wt;
                vis[u] = true;
            
                for(auto it : adj[u]){
                    int edgewt = it.second;
                    int v = it.first;
                    
                    if(!vis[v])
                    pq.push({edgewt,v});
                    
                }
                
            } 
            
        }
        
        return mst;
        
    }
};