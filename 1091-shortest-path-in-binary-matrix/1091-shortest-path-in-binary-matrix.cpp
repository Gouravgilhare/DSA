class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        q.push({0,0});
        grid[0][0]=1;

        int dx[] = {0,1,-1,0,1,-1,1,-1};
        int dy[] = {1,1,1,-1,-1,-1,0,0};
        int path=1;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [r,c] = q.front();
                q.pop();
                if (r == n-1 && c == n-1)
                    return path;
                for(int k = 0 ; k< 8 ; k++){
                    int nr = r + dx[k];
                    int nc = c + dy[k];

                    if(nr>=0 && nr< n && nc>=0 && nc< n && grid[nr][nc] == 0 ){
                        q.push({nr, nc});
                        grid[nr][nc]=1;
                    }

                }
            }

            path++;

        }

        return -1;
    }
};