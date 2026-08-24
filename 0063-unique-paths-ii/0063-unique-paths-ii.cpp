class Solution {
public:
    int helper( int i , int j , vector<vector<int>>& arr, vector<vector<int>>&dp){
        int n = arr.size() ,  m = arr[0].size();
        if(i== n-1 && j == m-1) return 1;
        if(i >= n || j >= m) return 0;
        if(arr[i][j] == 1) return 0;
        if(dp[i][j]!= -1) return dp[i][j];

        int right  = helper( i, j+ 1, arr, dp);
        int bottom  = helper(i+1 , j , arr, dp);

        return dp[i][j] = right  + bottom;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        int n = o.size() ,  m = o[0].size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        if(o[0][0] == 1 || o[n-1][m-1] == 1) return 0;
      return helper(0,0, o, dp);   
    }
};