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
       vi indegree(V);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
       
        for(int i =0; i< V; i++){
            if(indegree[i]==0)q.push(i);
        }
            int cnt= 0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            cnt++;
            
            for(auto &a : adj[node]){
                indegree[a]--;
                if(indegree[a]==0)q.push(a);
            }
        }    
        
        
        
        
        return !(cnt==V);
        
        
    }
};