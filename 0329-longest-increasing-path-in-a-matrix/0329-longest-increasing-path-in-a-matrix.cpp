class Solution {
public:
    int dfs(int i , int  j , vector<vector<int>>& matrix , vector<vector<int>>&dp ){
        int n = matrix.size();
        int m =  matrix[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int ans= 1;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k= 0 ; k<4 ; k++){
            int nr = dx[k] + i;
            int nc = dy[k] + j;

            if(nr>= 0 && nr < n && nc >= 0 && nc<m &&  matrix[nr][nc] > matrix[i][j]){
                ans = max( ans ,1+dfs(nr, nc, matrix,dp));

            }
        }

        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m =  matrix[0].size();

        vector<vector<int>>dp(n, vector<int>(m,-1));
        int ans = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                ans = max( ans, dfs(i,j,matrix, dp));
            }
        }


        return ans;
    }
};