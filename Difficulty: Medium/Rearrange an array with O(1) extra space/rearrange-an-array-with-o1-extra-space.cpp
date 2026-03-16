
class Solution {
  public:
    void arrange(vector<long long>& arr) {
        //  code here
       int n = arr.size();
       
       for(int i = 0 ; i< n ; i++){
           arr[i] += (arr[arr[i]]%n)*n;
       } 
       
       for(int i = 0 ; i< n ; i++){
           
           arr[i]/=n;
       }
       
    }
};

// 1 += (0%2)*2  = 1
// 0 += (1%2)*2  = 2

// arr[i]/=2
// 1 = 1/2 = 0
// 2 = 2/2 = 1