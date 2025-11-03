class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        int n = strs.size();

        map<string,vector<string>>mp;

        for(auto s : strs){
            string sorted =s;
            sort(sorted.begin(),sorted.end());

            if(mp.contains(sorted)){
                mp[sorted].push_back(s);
            }
            else{
                mp[sorted].push_back(s) ;
            }

        }

        for(auto it = mp.begin() ; it!= mp.end(); it++){
            ans.push_back(it->second);
        }
        return ans ;

    }
};