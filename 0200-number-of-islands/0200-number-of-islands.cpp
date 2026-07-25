class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>>&vis){
        int n = grid.size() , m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;

        int r[] = {-1,1,0,0};
        int c[] = {0,0,-1,1};

        while(!q.empty()){

            auto [row, col] = q.front();
            q.pop();
            vis[row][col] = 1;

            for(int i = 0 ; i< 4; i++){
                int l = row+r[i];
                int k = col + c[i];
                if(l>-1 && l <n && k > -1 && k < m && !vis[l][k] && grid[l][k] == '1'){
                    q.push({l,k});
                    vis[l][k]=1;
                }
            }    
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int island = 0;
        vector<vector<int>>vis(n, vector<int>(m,0));
        for(int i = 0 ; i< n ; i++){
            for(int j = 0; j< m; j++){

                if(grid[i][j] == '1' && !vis[i][j]){
                    island++;
                    bfs(i,j,grid,vis);
                }
            }
        }

        return island;
    }
};