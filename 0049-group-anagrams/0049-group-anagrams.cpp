class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n =  s.size();
        vector<vector<string>>ans;
        vector<string>temp;

        unordered_map<string,vector<string>>mp;

        for(auto a : s){
            string b = a;
            sort(b.begin(), b.end());
            mp[b].push_back(a);
        }
        
        for(auto it= mp.begin(); it!= mp.end(); it++){
            ans.push_back(it->second);
        }

        return ans;
    }
};