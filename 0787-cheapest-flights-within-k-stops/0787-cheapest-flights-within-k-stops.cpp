class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);
        for (auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // dist[node][edges_used]
        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        dist[src][0] = 0;

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}});   // edges_used, {node, cost}

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int edges = cur.first;
            int node  = cur.second.first;
            int cost  = cur.second.second;

            if (edges == k + 1) continue;

            for (auto &e : adj[node]) {
                int nextNode = e.first;
                int price    = e.second;

                if (cost + price < dist[nextNode][edges + 1]) {
                    dist[nextNode][edges + 1] = cost + price;
                    q.push({edges + 1, {nextNode, cost + price}});
                }
            }
        }

        int ans = 1e9;
        for (int i = 0; i <= k + 1; i++) {
            ans = min(ans, dist[dst][i]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};
