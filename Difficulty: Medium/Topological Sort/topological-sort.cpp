#define vi vector<int>
#define vvi vector<vector<int>>


class Solution {

    private:
        void dfs(int node, vvi & adj, vi &vis, stack<int>&st){
            vis[node]= 1;
            
            for(auto &a : adj[node]){
                if(!vis[a]) 
                    dfs(a, adj, vis,st);
            }
            
            st.push(node);
        }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vvi adj(V);
        vi vis(V), indegree(V);
        vi topo;
        stack<int>st;
        for(auto &e : edges){
            int u = e[0];
            int v= e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        for(int i= 0 ; i< V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        
        
        while(!q.empty()){
            int node = q.front();        
            q.pop();
            topo.push_back(node);
            for(auto &a : adj[node]){
                indegree[a]--;
                if(indegree[a]==0){
                    q.push(a);
                }
            }
        }
        
        return topo;
        
    }
};