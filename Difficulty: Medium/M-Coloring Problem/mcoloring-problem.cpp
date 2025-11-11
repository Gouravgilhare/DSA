class Solution {
  public:
  
    bool magic(int node,int v, int m , vector<int>&color, vector<vector<int>>&adj){
        if(node == v) return true;
        
        for(int c = 1 ; c<= m ; c++){
            bool isSafe = true;
            
            vector<int>temp = adj[node];
            
            for(int i = 0 ; i< temp.size(); i++){
                if(c == color[temp[i]]){
                    isSafe = false;
                    break;
                }
            }
            
            if(isSafe) {
                color[node] = c;
                if(magic(node+1, v,m,color,adj))return true;
                color[node] = 0;
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
        
        return magic(0,v,m,color,adj);
    }
};