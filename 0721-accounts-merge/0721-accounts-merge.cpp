class Solution {
public:
    unordered_map<string, string>par;
    unordered_map<string,int>rank;

    string find(string x ){
        if(par[x] == x) return x;

        return par[x] = find(par[x]);
    }

    void unionByRank(string a, string b){
        string parA = find(a);
        string parB = find(b);

        if(parA == parB) return ;

        if(rank[parA]==rank[parB]) {
            par[parB]= parA;
            rank[parA]++;
        }else if( rank[parA] > rank[parB]){
            par[parB] = parA;
        }else{
            par[parA] = parB;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, string>owner;


        for (auto a : accounts){
            for(int i =1 ; i < a.size(); i++)
            {
                par[a[i]] =  a[i]; // child parent
                rank[a[i]] = 0;
                owner[a[i]] = a[0];
            }
        }

        for(auto a : accounts)
        {   for(int i = 2; i< a.size() ; i++){
                unionByRank(a[1], a[i]);
            }
        }
        unordered_map<string, vector<string>>mp;
        vector<vector<string>>ans;

        for(auto &it : par){
            string root = find(it.first);
            mp[root].push_back(it.first);
        }


        for (auto &it : mp) {
            auto &emails = it.second;
            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(owner[it.first]);   // account name

            for (auto &email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};