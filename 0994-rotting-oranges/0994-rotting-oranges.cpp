class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        // int vis[n][m];
        int tm = 0,cntF=0;
        for(int i=0 ; i< n ; i++)
            for(int j = 0 ; j < m; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},tm});
                    grid[i][j]=2;
                }else if(grid[i][j]==1)cntF++;
            }   


        int dx[] = {1,-1,0,0};
        int dy []= {0,0,1,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t =q.front().second;
            tm = max(t, tm);
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr>=0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 ) {           
                    grid[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                    cntF--;
                }

            }

        }
          if(cntF>0)return -1;
            return tm;

    }
};