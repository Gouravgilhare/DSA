class Solution {
public:
    int time;
    vector<vector<int>> ans;
    vector<int>low,dt;
    void dfs(int u , int parU,  vector<vector<int>>&adj){
        dt[u] = low[u] = ++time;
        for(int  i = 0 ; i < adj[u].size(); i++){
            int v = adj[u][i];
            
            if(dt[v] == -1){
                dfs(v,u,adj);

                //updateLow
                low[u] = min(low[u], low[v]);

                //bridge
                if(low[v] > dt[u]){
                    ans.push_back({u,v});
                }
            }else if(v != parU){
                low[u] = min( low[u], dt[v]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        for(int i = 0 ; i< connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        low.resize(n);
        dt.resize(n, -1);

        for(int i = 0 ; i<n ; i++){
            if(dt[i]==-1){
                dfs(i,-1,adj);
            }
        }
        
        return ans;
    }
};