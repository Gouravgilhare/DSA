class Solution {
public:

    bool  helper(vector<vector<int>>& grid, int row, int  col,int  cnt ){
        int n = grid.size();
        if(cnt == n*n-1  )return true;
        if(grid[0][0]!=0)return false;
        if(cnt!= grid[row][col]) return false;

        int dx[8]={2 ,2,-2,-2,1,-1,1,-1};
        int dy[8]={1,-1,1,-1,2,2,-2,-2};
        
        int flag= false;
        for(int i= 0 ;i<8;i++){
            
                
                if(row+dx[i] >=0 && row+dx[i] <n && col+dy[i]>=0  && col+dy[i]<n && grid[row+dx[i]][col+dy[i]] == cnt+1)
                flag =helper(grid, row+dx[i],col+dy[i], cnt+1);
                if(flag)return true;
            
        }


        
        
        return false;   
        




    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return helper(grid, 0 ,0,0 );
    }
};