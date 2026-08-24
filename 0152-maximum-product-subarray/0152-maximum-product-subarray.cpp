class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0], minProd= nums[0], ans = nums[0];

        for(int i = 1; i<nums.size(); i++){
            int curr = nums[i];

            int newMax = max({curr, curr*maxProd, curr*minProd});
            int newMin = min({curr, curr*maxProd, curr*minProd});
            
            maxProd = newMax;
            minProd = newMin;
            ans = max(ans, maxProd);
        }

        return ans;
    }
};