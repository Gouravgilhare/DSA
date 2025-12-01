class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int n = matrix.size();
     int m = matrix[0].size();
     int i = 0 ;
     int left = 0 ; int right = m-1;
     while(left<=right && i<n){

        if(matrix[i][left]==target || matrix[i][right]==target)return true;

        if(target < matrix[i][right])left++;
        else i++; 



     }   


     return false;
    }
};