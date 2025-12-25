#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
// vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        // vvi adj(V);
        int V = graph.size();
        vi path(V,0), vis(V,0),check(V,0), safeNodes;
        
        
        for(int i =0 ; i< V; i++){
            if(!vis[i]){
                dfs(i,graph,vis,path,check);
            }
        }
        
        for(int i= 0 ; i<V; i++){
            if(check[i]==1)safeNodes.push_back(i);
        }
        
        return safeNodes;
    
    }
        // #define vi vector<int>
// #define vvi vector<vector<int>>
// class Solution {
    // private:
    bool dfs (int node, vvi &adj, vi &vis, vi& path, vi & check){
        vis[node]=1;
        path[node]=1;
        check[node]=0;

        for(auto a: adj[node]){
            if(!vis[a]){
                if(dfs(a,adj,vis,path,check)) {
                    check[node]=0;
                    return true;
                }
            }else if(path[a]){
                check[node]=0;
                return true;
            }
        }
        path[node]=0;
        check[node]=1;
        return false;
        
    }
    
//   public:
    
};
    