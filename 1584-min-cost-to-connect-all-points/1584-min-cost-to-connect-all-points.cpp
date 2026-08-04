class Solution {
public:
    int manHattan(vector<vector<int>>&points, int a, int b){
        return abs(points[a][0] - points[b][0])
            +  abs(points[a][1] - points[b][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>minSet(n,0);
        pq.push({0,0});
        int minCost = 0;
        
        while(!pq.empty()){
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;
            pq.pop();
            if(minSet[node]) continue;
            minCost += wt;

            minSet[node] = 1;
            for(int i = 0 ; i< n ; i++){
                if(!minSet[i]){
                    int edgeWt = manHattan(points, node, i);
                    pq.push({edgeWt , i});
                }
            }
        }

        return minCost;

    }
};