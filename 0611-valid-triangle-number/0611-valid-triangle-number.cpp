class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int currSum = 0;
        int cnt = 0;

        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i =n-1 ; i >0; i--){
            int left = 0;
            int right = i-1;

           while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    ans += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ans;
    }
};