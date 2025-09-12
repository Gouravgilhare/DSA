class Solution {
  public:
  
    bool isPossible(vector<int>&arr, int k , int dist){
        int lastpos = arr[0];
        int cow = 1;
        for(int i= 1; i< arr.size(); i++){
            if(arr[i]-lastpos >= dist){
                cow++;
                lastpos = arr[i];
        
                if(cow >= k )return true;
                
            }
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls.back()- stalls.front();
        int ans= 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(stalls, k , mid)){
                ans= mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
            
        }
        return ans;
    }
};