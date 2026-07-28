class Solution {
public:
    void bfs(int node , vector<vector<int>>& isConnected, vector<int>&vis){
        int n = isConnected.size();
        int m = isConnected[0].size();

        queue<int>q;
        q.push(node);
        vis[node]=1;

        int dx[] ={1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i = 0 ; i<isConnected.size( ); i++){
                if(isConnected[curr][i]==1 && !vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }

        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        int province = 0;
        vector<int>vis(n,  0);

        for(int i = 0 ; i< n ; i++){

            if(!vis[i]){
                bfs(i,  isConnected, vis);
                province++;
            }

        }

        return province;
    }
};