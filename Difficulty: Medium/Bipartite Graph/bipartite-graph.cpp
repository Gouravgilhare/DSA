#define vi vector<int> 
#define vvi vector<vector<int>>


class Solution {
    private:
        bool check(int V, int node, vvi &adj, vi&col){
            
            queue<int>q;
            q.push(node);
            col[node]=0;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                
                for(auto &a : adj[temp]){
                    if(col[a]==-1){
                        col[a] = !col[temp];
                        q.push(a);
                    }else if (col[a] == col[temp]){
                        return false;
                    }
                }
                
            }
            
            return true;
        }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vi color(V,-1);
        vvi adj(V);
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // color[0]=0;
        
        for(int i= 0 ; i< V; i++){
            if(color[i]==-1){
                if(!check(V,i,adj,color)){
                    return false;
                }
            }
        }
        
        return true;
    }
};