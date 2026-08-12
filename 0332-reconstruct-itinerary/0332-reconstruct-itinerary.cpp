class Solution {
public:
    unordered_map<string, vector<string>>adj;
    vector<string>result;
    int num = 0;

    void dfs(string from  ){
        
        while(!adj[from].empty()){

            string to = adj[from].back();

            adj[from].pop_back();

            dfs(to);

            // adj[from].push_back(to);
        }

        result.push_back(from);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        num = tickets.size();
        for(auto &t : tickets){
            adj[t[0]].push_back(t[1]);
        }
        

        for(auto &it : adj ){
            sort(it.second.rbegin(), it.second.rend());
        }

        string jfk = "JFK";
        dfs(jfk);

        reverse(result.begin(), result.end());

        return result;
    }
};