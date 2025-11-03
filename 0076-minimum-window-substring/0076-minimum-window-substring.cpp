class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int>mp(256,0);
        int minLen = INT_MAX;
        int sIndex = -1;
        int m = t.size(), n =s.size();
        int cnt = t.size();
        int l = 0, r= 0;

        for(auto k : t){
            mp[k]++;
        }

            while(r< n){
                if(mp[s[r]]>0){
                    cnt--;
                
                }
                    mp[s[r]]--;
                while(cnt==0){

                    if(r-l+1< minLen){
                        minLen = r-l+1;
                        sIndex = l;
                    }
                    mp[s[l]]++;
                    if(mp[s[l]]>0)cnt++;
                    l++;
                }
                r++;
    }
        return minLen==INT_MAX?"" : s.substr(sIndex,minLen);
    }
};