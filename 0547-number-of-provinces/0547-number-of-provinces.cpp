class Solution {
public:
 void dfs(int node, vector<vector<int>>&adjls, vector<int>&vis){
        vis[node] = 1;
        for(auto it : adjls[node])
            if(!vis[it]) 
                dfs(it, adjls,vis);
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>>adjls(V);
        for(int i = 0 ; i <V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int>vis(V,0);
        for(int i = 0 ; i < V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        
        return cnt;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        return numProvinces(isConnected,isConnected.size());
    }
};