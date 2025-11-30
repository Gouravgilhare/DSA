class Solution {
  public:
    bool isSafe(vector<vector<int>>&adj, int color,vector<int>&colors, int node){
        int n = adj[node].size();
        
            
        for(auto a : adj[node]){
            if(color == colors[a])return false;
        }
        
        return true;
    }

    bool helper(int node, vector<int> &colors, int m ,vector<vector<int>>&adj){
        
       int n = adj.size();
       
       if(node == n)return true;
       
       
       for(int i = 1 ; i<=m ; i++ ){
           
           if(isSafe(adj, i, colors,node)){
               colors[node]= i;
               
               if(helper(node+1, colors,m,adj))
                    return true;
                
                colors[node]=-1;
           }
       }
       
       
       return false;
        
        
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here

        vector<vector<int>>adj(v);
        
        for(auto edge : edges){
            int u = edge[0];
            int w = edge[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        
        vector<int>colors(v,-1);
        
        return helper(0, colors, m ,adj);
    }
};