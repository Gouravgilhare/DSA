class Solution {
  public:
    bool detectCycle(vector<vector<int>>&adj, vector<int>&vis, int src){
        
        queue<pair<int,int>>q;
        
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto a : adj[node]){
                if(!vis[a])
                {
                    q.push({a,node});
                    vis[a]=1;
                }else if( parent != a){
                    return true;
                }
            }
            
        }
        
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        vector<int>vis(V,0);
        vector<vector<int>>adj(V);
        for(int i =0 ; i< n ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                if(detectCycle(adj, vis, i)) return true;
            }
        }
        
        return false;
        
        
    }
};