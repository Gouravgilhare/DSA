class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();

        int l = 0 ; int r =0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0;
        
        while(l< n && r<m){
            if(g[l] <= s[r]){
                cnt++;
                l++;
                r++;
            }else {
                r++;
            }
        }

        return cnt;


    }
};