class Solution {
public:
    bool helper(vector<vector<int>>&grid, int row, int col , int index, vector<pair<int, int>>&pos){
        
        int n = grid.size();
        
        if(row < 0 || row>= n || col < 0 || col >= n||index != grid[row][col] )
            return false;
        if(index == (n*n -1)) return true;
        

        for(int k = 0 ; k< n*n-1; k++){
            auto [r1,c1]  = pos[k];
            auto [r2,c2]  = pos[k+1];

        int dx= abs(r1-r2);
        int dy= abs(c2-c1);

        if(!((dx == 2 && dy == 1) || (dx==1 && dy==2)))return false;

        }
        
        return true;
        
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!= 0) return false;
        
        int n = grid.size();
        vector<pair<int, int>>pos(n*n);
        for(int i = 0 ; i< n; i++){
            for(int j = 0 ; j< n ; j++){
                pos[grid[i][j]] = {i,j};
            }
        }

        
        return helper(grid, 0,0,0, pos);
    }
};