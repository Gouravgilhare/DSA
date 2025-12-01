class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest = INT_MIN;
        int secLargest = INT_MIN;
        int n  = arr.size();
        for(int i = 0 ; i< n ; i++){
            
            
            if(arr[i] > largest ){
                secLargest = largest;
                largest = arr[i];
            }else if(arr[i]<largest && arr[i] > secLargest){
                secLargest = arr[i];
            }
        }
        
        return secLargest;
    }
};