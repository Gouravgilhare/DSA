class Solution {
  public:
   bool isSafe(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        for (int neighbor : adj[node]) {
            if (color[neighbor] == col) 
                return false;
        }
        return true;
    }
    bool magic(int node, int v, int m, vector<int>&color, vector<vector<int>>&adj){
        
        
        if(node == v) return true;
        
        for(int i = 1 ; i<= m; i++){
         
            
            if(isSafe(node, i, color,adj)){
                color[node] = i ;
                
                if(magic(node+1, v, m, color, adj))
                    return true;
                color[node]=0;
            }
            
        }
        return false;
        
        
    }
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>>adj(v);
        
        for(int i = 0 ; i< edges.size(); i++){
            int u = edges[i][0];
            int w = edges[i][1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        
        vector<int>color(v,0);
        
        return magic(0, v,  m, color, adj);
        
    }
};