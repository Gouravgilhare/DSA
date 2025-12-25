#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
         vvi adj(N);
         vi indegree(N);
        
        for(auto &it : prerequisites ){
            adj[it.first].push_back(it.second);
            indegree[it.second]++;
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