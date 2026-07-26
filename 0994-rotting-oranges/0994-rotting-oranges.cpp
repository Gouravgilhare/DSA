class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        int fresh= 0;
        queue<pair<int,int>>q;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        if(fresh==0) return 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        int mins = 0;
        while(!q.empty()){
            int size = q.size();
            bool rotten = false;
            
            while(size--){

                auto [row, col] = q.front();
                q.pop();


                for(int i = 0 ; i<4; i++){
                    int nr = row+dx[i];
                    int nc = col + dy[i];

                    if(nr>=0 && nr<n  && nc>=0 && nc < m && grid[nr][nc]==1){
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        fresh--;
                        rotten= true;
                    }
                }

            }
                if(rotten) mins++;
        }

        return fresh == 0? mins: -1;
    }
};