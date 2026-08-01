class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>ans(n, vector<int>(m,-1));

        for(int i= 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(int k = 0 ; k< 4; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr>=0 && nr< n && nc>=0 && nc < m && ans[nr][nc] == -1 ){
                    ans[nr][nc] = ans[r][c] + 1 ;
                    q.push({nr,nc});
                }

            }

        }
        return ans;
    }
};