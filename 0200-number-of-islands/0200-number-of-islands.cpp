class Solution {
public:
    vector<int>par,rank;

    //find
    int find(int x){
        if(par[x] == x) return x;

        return par[x] = find(par[x]);
    }

    bool unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA  == parB) return false;

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] < rank[parB]){
            par[parA]= parB;
        }else{
            par[parB] = parA;
        }

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        par.resize(n*m);
        rank.resize(n*m, 0);

        for(int i = 0 ; i< n*m ; i++){
            par[i]=i;
        }    

        int island = 0;

        for(int i = 0; i<n ; i++){
            for(int j = 0 ; j< m ; j++){
                if(grid[i][j] == '1'){
                    island++;
                }
            }
        }

        int dx[] = {1,-1, 0, 0 };
        int dy[] = {0, 0, 1, -1 };

        for(int i = 0; i< n ; i++){
            for(int j = 0 ; j< m ; j++){

                if(grid[i][j]=='0') continue;

                int node = i*m + j;

                for(int k = 0 ; k< 4; k++){

                    int nr = i + dx[k];
                    int nc = j + dy[k];
                
                    if(nr<0 || nr>= n || nc<0 || nc>= m) continue;

                    if(grid[nr][nc]=='0'){
                        continue;
                    }

                    int adjNode = nr*m + nc;

                    if(unionByRank(node, adjNode)){
                        island--;
                    }

                }

            }
        }
            return island;

    }
};