class Solution {
public:
    double dfs(string curr, string target,unordered_map<string, vector<pair<string,double>>>&graph,  unordered_set<string>&vis){
        if(curr == target) return 1.0;

        vis.insert(curr);

        for(auto & [n,w] : graph[curr]){
            if(vis.count(n)) continue;
            double res = dfs(n,target, graph,vis);
            if(res != -1.0){
                return res = res*w;
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>>graph;

        //buildgraph
        for(int i = 0 ; i< equations.size(); i++){
            string a = equations[i][0]; 
            string b = equations[i][1]; 
            double v = values[i];
        
            graph[a].push_back({b, v});
            graph[b].push_back({a, 1.0/v});
        }
        vector<double>ans;

        // process queries
        for(auto &q : queries){
            string start = q[0];
            string target = q[1];

            if(!graph.count(start) || !graph.count(target)){
                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string>vis;

            double res = dfs(start, target, graph, vis);
            ans.push_back(res);
        }

        return ans;
    }
};