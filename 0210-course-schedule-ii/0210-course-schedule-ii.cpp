class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
     int n = numCourses;
    vector<int>indegree(n,0);
     vector<vector<int>>adj(n);


        for(auto &p: pre){
            int course = p[0];
            int pr = p[1];

            adj[pr].push_back(course);
            indegree[course]++;

        }


        queue<int>q;
        for(int i =0 ; i< n ; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>order;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            order.push_back(node);

            for(int next : adj[node]){

                indegree[next]--;
                if(indegree[next]==0)q.push(next);
            }
        }

        if(order.size()==n){
            return order;
        }

        return {};

    }
};