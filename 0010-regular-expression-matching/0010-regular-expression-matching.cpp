class Solution {
public:
    vector<vector<int>>memo;
    bool dp(int i ,int  j, string&s, string&p){

        if(memo[i][j]!=-1) return memo[i][j];

        bool ans= false;

        if(j == p.size()){
            ans = (i == s.size());
        }else{
            bool firstMatch = (i < s.size()  && (s[i] == p[j]  || p[j]=='.'));

            if(j + 1 < p.size() && p[j+1] == '*'){
                ans = dp(i,j+2,s, p) || (firstMatch  && dp(i+1, j , s,p));
            }else{
                ans = firstMatch && dp(i+1, j+1, s, p);
            }
        }

        return memo[i][j]=ans;

    }

    bool isMatch(string s, string p) {
        memo.assign(s.size()+1, vector<int>(p.size() + 1 , -1));
        return dp(0,0,s,p);    
    }
};