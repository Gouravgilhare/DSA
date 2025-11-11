class Solution {
  public:
  
    
  
    void merge(vector<int>& nums, int l,int q, int r) {
        
        int n = q-l+1;
        int m = r-q;
        vector<int>left(n );
        vector<int>right(m);
        
        for(int i = 0 ; i < n; i++){
            left[i] = nums[i+l];
        }
        
        for(int i = 0 ; i <m; i++){
            right[i] = nums[i+q+1];
        }
        
        int i = 0, j = 0, k =l;
    
        
        while(i<n && j < m){
            if( left[i] <= right[j]){
                nums[k++] = left[i++];
                
            }else{
                nums[k++] = right[j++];
            }
        }
        
        while(i<n)nums[k++] = left[i++];
        while(j<m)nums[k++] = right[j++];
        
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r) return;
        
        int q = l + (r-l)/2;
        mergeSort(arr,l,q);
        mergeSort(arr,q+1,r);
        merge(arr,l,q,r);
    }
};