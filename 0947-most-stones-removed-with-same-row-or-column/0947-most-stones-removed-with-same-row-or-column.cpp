class DisjointSet{
    public:
         vector<int>par, rank,size;

    DisjointSet(int s){
        rank.resize(s,0);
        size.resize(s,1);
        for(int i = 0 ; i< s ; i++) par.push_back(i);

    }

    int find(int x){
        if(x == par[x])return x;

        return par[x] = find(par[x]);
    }

    bool unionByRank(int a ,int b){
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return false;
    
        if(rank[parA] == rank[parB]) {
            par[parB] = parA;
            rank[parA]++;
        }else if( rank[parA] > rank[parB] ){
            par[parB] = parA;
        }else {
            par[parA] = parB;
        }

        return true;
    }

    bool unionBySize(int a, int b){
        int pa = find(a);
        int pb = find(b);
    
        if(pa == pb) return false;

        if(size[pa] < size[pb]){
            swap(pa , pb);
        }
        par[pb] = pa;
        size[pa] += size[pb];
        

        return true;
    }
};

class Solution {
public:

   

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        int maxRow = 0 , maxCol = 0;

        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);

        unordered_set<int>stoneNodes;

        for(auto it: stones){
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
        
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes.insert(nodeRow);
            stoneNodes.insert(nodeCol);
        }

        int cnt = 0 ;

        for(auto it : stoneNodes){
            if(ds.find(it)== it) cnt++;
        }
        return n-cnt;
    }
};