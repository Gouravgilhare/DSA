class TreeAncestor {
public:

    vector<vector<int>>up;
    int Log;
    void fillAnc(vector<vector<int>>& anc, int n, vector<int>&adj){
        
    }

    
    TreeAncestor(int n, vector<int>& parent) {
        Log = 20;
        up.assign(n, vector<int>(Log, -1));

        for(int i = 0 ; i< n; i++){
            up[i][0]=parent[i];
        }


        for(int j = 1 ; j< Log; j++){
            for(int i = 0 ; i< n ;i++){
                
                if(up[i][j-1] != -1){
                    up[i][j]=up[up[i][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {

            for(int j = 0 ; j< Log; j++){
                if(k & (1<< j)){
                    node  = up[node][j];
                    if(node == -1) break;
                }
            }
    

        return node;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */