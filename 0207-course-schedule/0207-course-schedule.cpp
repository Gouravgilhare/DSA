#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& p) {
        vvi adj(N);
         vi indegree(N);
        
        for(auto &it : p ){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int>q;
        for(int i=0; i<N; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        
        vi topo;
        while(!q.empty()){
            int node  =q.front();
            q.pop();
            topo.push_back(node);
            for(auto &a: adj[node]){
                indegree[a]--;
                if(indegree[a]==0)
                    q.push(a);
            }
        }
        
        return (topo.size()==N);
    }
};