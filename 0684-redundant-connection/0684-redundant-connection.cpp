class Solution {
public:
    vector<int>par, rank;

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    bool unionByRank(int a, int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return false;

        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if (rank[parA] > rank[parB]){
            par[parB] = parA; 
        }else par[parA] = parB; 

        return true;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        int node = n-1;
        par.resize(n+1);
        rank.resize(n+1);

        for(int i=0 ; i< n ; i++ ){
            par[i]=i;
            rank[i]= 0;
        }

        for(auto &e : edges){
            int a = e[0];
            int b = e[1];

            if(find(a) == find(b)){
                return {a,b};
            }

            unionByRank(a, b);
        }

        return {};
    }
};