class Solution {
  public:
    vector<int>par, rank,size;
    
    int find(int x) {
        if(x == par[x]) return x;
        
        return par[x]=find(par[x]);
    }
    
    bool unionByRank(int a, int b){
        int pa = find(a);
        int pb = find(b);
        
        if(pa == pb) return false;
        
        if(rank[pa] == rank[pb]){
            par[pb] = pa;
            rank[pa]++;
        }else if( rank[pa] > rank[pb]){
            par[pb] = pa;
        }else 
            par[pa] = pb;
            
            
        return true;
    }
    
    bool unionBySize(int a, int b){
        int pa = find(a);
        int pb = find(b);
        
        if( pa  ==  pb ) return false;
        
        if(size[pa] > size[pb]){
            swap( pa, pb );
        }
        
        par[pb] = pa;
        size[pa] += size[pb];
        rank[pa]++;
        
        return true;
        
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        rank.resize(V,0);
        par.resize(V);
        size.resize(V,1);
        
        for(int i = 0 ; i< V ;i++){
            par[i] = i;
        }
        
        sort(edges.begin(), edges.end(),[](const vector<int>&a,const vector<int>&b){
            return a[2] < b[2];
        });
        
        int W = 0;
        
        for(auto it : edges){
            if(unionBySize(it[0] , it[1] )){
                W += it[2];
            }
        }
        
        
        return W;
    }
};