class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

     int ans = 1; int left = 0;

    int cnt = 0;
    int n = nums.size();
        if (k <= 1) return 0;
    
     for(int i=0 ; i < n ; i++){
        ans *= nums[i];
        while(ans >= k){
            ans /= nums[left];
            left++;
        }
        if(ans<k) cnt+=i-left+1;
     }   


     return cnt;
    }
};