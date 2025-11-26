class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minLen = INT_MAX, start= -1;
        int mp[256] = {0};
        int  i = 0,l= 0, r= 0, cnt = m;
       
            while(i<m){
                mp[t[i]]++;
                i++;
            }
        
            while(r<n){
                if(mp[s[r]] > 0) cnt--;
                mp[s[r]]--;
                r++;
                while(cnt == 0)
                {
                    if(r-l< minLen){
                        minLen = r-l;
                        start = l;
                    }
                        mp[s[l]]++;
                        if(mp[s[l]]>0) cnt++;
                        l++;
                }
                // r++;
            }
        

        return (start == -1? "" : s.substr(start, minLen));
    }
};