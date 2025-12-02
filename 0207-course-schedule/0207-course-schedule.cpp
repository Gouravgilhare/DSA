class Solution {
public:
    bool canFinish(int nC, vector<vector<int>>& p) {
        int n = nC;

        vector<vector<int>>adj(n);

        vector<int>indegree(n);
        for(int i=0 ; i< p.size() ; i++){
            int a= p[i][0];
            int b= p[i][1];
            adj[b].push_back(a);
            indegree[a]++;
            // adj[a].push_back(b);
        }   


        queue<int>q;
        for(int i = 0 ; i<n ;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            cnt++;

            for(auto next : adj[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }


        }

        return cnt==n;
    }
};