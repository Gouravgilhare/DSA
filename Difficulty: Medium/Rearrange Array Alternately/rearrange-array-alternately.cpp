class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        int n= arr.size();
        sort(arr.begin(), arr.end());
        int i =0 ;
        vector<int>temp=arr;
        vector<int>demo=arr;
        reverse(demo.begin(), demo.end());
        
        int k=0;
        
        while(i<n){
            arr[i] = demo[k++];
            i = i+2;
        }
        
        i = 1;
        int j= 0;
        while(i<n){
            arr[i] = temp[j++];
            i = i+2;
        }
        
        
        
        
        
    }
};