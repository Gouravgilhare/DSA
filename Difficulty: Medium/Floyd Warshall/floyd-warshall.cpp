// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &matrix) {
        // Code here
        int n = matrix.size();
        
        // for(int i =0 ; i< n ; i++){
        //     for(int j =0 ; j< n ; j++){
        //         if(matrix[i][j] == 1e8){
        //             matrix[i][j] = -1;
        //         }        
        //         if(i==j)
        //             matrix[i][j]=0;
        //     }
        // }
        
        for(int k= 0 ; k< n ; k++){
            for(int i =0; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(matrix[i][k] < 1e8 && matrix[k][j] < 1e8)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
        
        
        
        
    }
};