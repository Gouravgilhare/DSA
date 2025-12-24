#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
    private: 
    bool dfs(int node, vi &vis, vi&path, vvi&adj){
        vis[node]=1;
        path[node]=1;
        for(auto a : adj[node]){
            if(!vis[a]){
                if(dfs(a,vis,path,adj))return true;
            }
            else if(  path[a] ) 
            return true;
        }
        
        path[node]=0;
        
        
        return false;
        
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vvi adj(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
        }
        
        vi path(V, 0);
        vi vis(V,0);
        
        for(int i =0; i< V; i++){
            if(!vis[i]){
                if(dfs(i,vis,path, adj)) return true;
            }
        }
        
        return false;
        
        
    }
};