class Solution {
public:
    vector<int>par, rank,size;

    int find(int x){
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    bool unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return false;

        if(rank[parA] == rank[parB] ){
            par[parB] = parA;
            rank[parA]++; 
            size[parA] += size[parB];
        }
        else if (rank[parA] > rank[parB]){
            par[parB] = parA;
            size[parA] += size[parB];
        }else {
            par[parA] = parB;
            size[parB] += size[parA];
        }
        return true;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        par.resize(n*m); 
        rank.resize(n*m,0);
        size.resize(n*m, 1);
        for(int i = 0 ; i< n*m ; i++){
            par[i] = i;
        } 

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int isLands = 0;
        for(auto g : grid){
            for(auto b : g)
                if(b == 1)  isLands++;
        }
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m; j++){

                if(grid[i][j]==0) continue;
                
                int node = i*m + j;

                for(int k = 0 ; k < 4; k++ ){
                    int nr = i + dx[k];
                    int nc = j + dy[k];

                    if(nr <0 || nr>= n || nc < 0 || nc >= m) continue;

                    if(grid[nr][nc]==0) continue;

                    int adjNode = nr*m + nc;

                    if(unionByRank(node, adjNode)){
                        isLands--;
                    }

                }

            }

        }
        int maxArea =0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j]==1){
                    int root = i * m + j;
                    maxArea = max(maxArea, size[root]);
                }
            }
        }
        return maxArea;
    }
};