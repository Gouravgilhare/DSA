class Solution {
public:
    bool isPalin(int i , int j , string &str){
        while(i<j){
            if(str[i] != str[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);

        for(int i =n-1; i>=0 ; i--){
            int  minCost = 1e9;
            for(int j = i; j<n; j++){
                if(isPalin(i,j,s)){
                    int cost  = 1+ dp[j+1];
                    minCost = min(cost, minCost);
                }
            }

            dp[i]= minCost;
        }

        return dp[0]-1;
    }
};