#define vi vector<int>
#define vvi vector<vector<int>>
class Solution {
    private:
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
    
  public:
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        vvi adj(V);
        vi safeNodes;
        vi indegree(V,0);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++;
            
        }
        queue<int>q;
        for(int i =0 ; i< V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node  =q.front();
            q.pop();
            safeNodes.push_back(node);
            
            for(auto &a : adj[node]){
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
        }
        
        sort(safeNodes.begin(),safeNodes.end());
        
        // for(int i= 0 ; i<V; i++){
        //     if(check[i]==1)safeNodes.push_back(i);
        // }
        
        return safeNodes;
    }
};