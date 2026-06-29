class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l[3]={-1,-1,-1};
        int cnt = 0;
        for(int i=0 ; i<n ; i++){
            l[s[i]-'a']=i;
            if(l[0]!=-1 && l[1]!=-1 && l[2]!=-1){
                cnt += 1 + min(l[0], min(l[1], l[2]));
            }
        }

        return cnt;
       
    }
};