class Solution {
  public:
    // int  nextBig(vector<int>&a,int  i,  int val){
    //     int n = arr.size();
    //     sort(arr.begin()+i+1, arr.end()); 
    //     int temp ;
    //     for(int j = i+1 ; j< n; j++){
    //         if(arr[j] > val){
    //             temp = arr[j];
    //             break;
                
    //         }
    //     }
        
    //     return temp;
        
    // }
    void nextPermutation(vector<int>& arr) {
        // code here
        int  n =arr.size();
        int ind = -1;
        for(int i = n-2  ; i>= 0 ; i--){
            if(arr[i] < arr[i+1]){
                ind = i;
                // sort(arr.begin()+ i, arr.end());
                break;
            }
            
        }
        if(ind  == -1 ){
            reverse(arr.begin(), arr.end());
        
            return;
        }
        
        for(int i = n-1; i > ind; i--){
            if(arr[i] > arr[ind]){
                swap(arr[i], arr[ind]);
                
            break;
            }
        }
        
        
        reverse(arr.begin()+ind+1, arr.end());
            
    }
};