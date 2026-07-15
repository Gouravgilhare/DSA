class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        int arr[n];
        for(int i = 0 ; i< n ; i++){
            if(nums[i] > n || nums[i] <=0 ){
                nums[i] = INT_MAX;
            }
        }

        //marking
        for(int i = 0 ; i < n ; i++){
            int b = abs(nums[i]);
            if(b > n) continue;

            if(nums[b-1] > 0 ){
                nums[b-1] = -nums[b-1];
            }
        }

        //find first missing p number
        for(int i = 0 ; i< n ; i++){
            if(nums[i]> 0) return i+1;
        }


        return n+1;
    }
};