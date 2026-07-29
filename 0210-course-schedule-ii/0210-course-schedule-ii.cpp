class Solution {
public:
    bool isCycle(int src , vector<bool>&vis, vector<bool>&recPath ,vector<vector<int>>& edges ){
        vis[src]=true;
        recPath[src]=true;

        for(int i = 0 ; i< edges.size(); i++){
            int v = edges[i][0];
            int u = edges[i][1];
            
            if(u == src){
                if(!vis[v]){
                    if(isCycle(v,vis,recPath,edges)) return true;
                }else if( recPath[v]){
                        return true;
                }
            }
        }
        recPath[src] = false;
        return false;
    }

    void topoSort(int src, vector<bool>&vis, stack<int>&st, vector<vector<int>>& edges){
        vis[src] = true;

        for(int i = 0 ; i< edges.size() ;i++){
            int v = edges[i][0];
            int u = edges[i][1];
            if(u==src)
            if(!vis[v]){
                topoSort(v,vis,st,edges);
            }
        }

        st.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        vector<int>ans;

        for(int i =0 ; i< n ; i++){
            if(!vis[i]){
                if(isCycle(i, vis, recPath, edges))
                    return ans;
            }
        }

        stack<int>st;
        vis.assign(n,false);

        for(int i= 0; i< n ; i++){
            if(!vis[i]){
                topoSort(i, vis, st, edges);
            }
        }


        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }


        return ans;
    }
};