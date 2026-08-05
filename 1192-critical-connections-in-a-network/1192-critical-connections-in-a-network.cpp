class Solution {
public:
    vector<int> disc, low;
    vector<vector<int>> ans;
    int timer = 0;

    void dfs(int node, int parent, vector<vector<int>>& adj) {
        disc[node] = low[node] = timer++;

        for (int neigh : adj[node]) {
            if (neigh == parent)
                continue;

            if (disc[neigh] == -1) {
                dfs(neigh, node, adj);

                low[node] = min(low[node], low[neigh]);

                // Bridge condition
                if (low[neigh] > disc[node]) {
                    ans.push_back({node, neigh});
                }
            } else {
                // Back edge
                low[node] = min(low[node], disc[neigh]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        vector<vector<int>> adj(n);

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        disc.assign(n, -1);
        low.assign(n, -1);

        dfs(0, -1, adj);

        return ans;
    }
};