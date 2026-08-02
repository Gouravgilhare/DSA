class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, string>owner;
        unordered_map<string ,vector<string>> adj   ;

        for(auto &ac : accounts){
            for(int i = 1 ; i< ac.size(); i++){
                owner[ac[i]] = ac[0];
            }
            for(int i= 2; i<ac.size(); i++){
                adj[ac[1]].push_back(ac[i]);
                adj[ac[i]].push_back(ac[1]);
            }
        }
        unordered_set<string>vis;
        vector<vector<string>>ans;
        
        for(auto &it : owner){
            
            string email = it.first;

            if(vis.count(email)){
                continue;
            }

            queue<string>q;
            q.push(email);
            vis.insert(email);

            vector<string>temp;

            while(!q.empty()){
                string email2 = q.front();
                q.pop();
                temp.push_back(email2);

                for(auto &c : adj[email2] ){
                    if(!vis.count(c)){
                        vis.insert(c);
                        q.push(c);
                    }
                }
            }
            sort(temp.begin(), temp.end());
            temp.insert(temp.begin(), owner[email]);
            ans.push_back(temp);    
        }

        return ans;
    }
};