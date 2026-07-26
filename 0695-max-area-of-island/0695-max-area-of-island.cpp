class Solution {
public:
    int bfs(int i , int j , vector<vector<int>>&grid){
        int n  = grid.size();
        int m  = grid[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 0;
        int area = 1;

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0 ; i< 4 ; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];

                if(nr>-1 && nr <n && nc > -1 && nc < m  && grid[nr][nc]==1){
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                    area++;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt= 0;
        for(int i = 0 ; i<n ;i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j]==1)
                {
                    cnt = max(cnt,bfs(i,j,grid));
                }
            }
        }
        return cnt;
    }
};