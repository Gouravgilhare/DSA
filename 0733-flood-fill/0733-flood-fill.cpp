class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;
        q.push({sr,sc});
        int original = image[sr][sc];
        if(original == color)return;
        image[sr][sc] = color;

        int dx[] ={1,-1,0,0};
        int dy[] ={0,0,-1,1};
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i<4; i++){
                int nr = row+dx[i];
                int nc = col+dy[i];

                if(nr >-1 && nr< n && nc>-1 && nc<m && image[nr][nc]==original){
                    image[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        } 
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        helper(image, sr,sc,color);
        return image;
    }
};