class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int l = 0, r= 0;
        int maxLen = -1;
        unordered_map<char,int>mp;
        
        while(r<n){
            mp[s[r]]++;
            if(mp.size()>k){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
            if(mp.size()==k){
                maxLen = max (maxLen, r-l+1);
            }
            r++;
        }
        
        return maxLen;
    }
};