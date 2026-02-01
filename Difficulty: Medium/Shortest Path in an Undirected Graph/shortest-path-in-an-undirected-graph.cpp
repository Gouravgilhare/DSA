class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        vector<int>dist(n+1, 1e9);
        dist[1] = 0 ;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
        
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            
        }
        vector<int>parent(n+1, -1);
        parent[1] = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,1});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(dis > dist[node]) continue;
            
            for(auto it : adj[node]){
                int adjNode= it.first;
                int edw = it.second;
                
                if(dis+edw < dist[adjNode]){
                    dist[adjNode] = dis+edw;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        if(dist[n]==1e9)return {-1};
        
        vector<int>path;
        int node = n;
         while(parent[node] != node){
             path.push_back(node);
             node = parent[node];
         }
        path.push_back(1);
        reverse(path.begin(), path.end());
        
        vector<int>ans;
        ans.push_back(dist[n]);
        for(auto x : path) ans.push_back(x);
        
        
        return ans;
    }
};