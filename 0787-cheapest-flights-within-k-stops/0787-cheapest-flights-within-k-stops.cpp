class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //adj
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : flights){

            adj[it[0]].push_back({it[1],it[2]});
        }

        //pq 
        queue<pair<int, pair<int,int>>>q;
        vector<int>dist(n, 1e9 );
        dist[src]=0;
        q.push({0,{src,0}}); //distance , node

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            if(stops > k) continue;
            
            for(auto &it : adj[node]){
                int edw = it.second;
                int adjNode = it.first;

                if(dis + edw < dist[adjNode]){
                    dist[adjNode] = dis + edw;
                    q.push({stops +1 ,{adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};