class Solution {
    private:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int iniColor, vector<vector<int>>&ans){
            int n = image.size(), m = image[0].size();
        ans[sr][sc] = color;
        int dx[4] = {1,-1, 0,0};
        int dy[4] = {0,0, 1,-1};
        
        
        for(int k = 0; k < 4; k++){
            int nr = sr+dx[k];
            int nc = sc+dy[k];
            if(nr>= 0 && nr < n && nc >= 0 && nc < m && ans[nr][nc]==iniColor){
                dfs(image, nr,nc,color,iniColor, ans);
            }
        }



    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){

        int iniColor = image[sr][sc];
            int n = image.size(), m = image[0].size();
        if(iniColor == color) return image;
        
        vector<vector<int>>ans = image;
        dfs(image, sr,sc,color, iniColor, ans);

        return ans;
    }
};