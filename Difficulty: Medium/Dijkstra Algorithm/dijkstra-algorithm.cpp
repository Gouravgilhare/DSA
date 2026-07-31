class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        
        for(auto a : edges ){
            
            //src               //node   //dist
            adj[a[0]].push_back({a[1], a[2]});
            adj[a[1]].push_back({a[0], a[2]});
        }
        
        //pq
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>dist(V , 1e9);
        dist[src]=0;
        pq.push({0,src});
        
        
        while(!pq.empty()){
            int node =  pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(dis > dist[node]) continue;
            
            
            for(auto it: adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                if(dis+edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
        
    }
};