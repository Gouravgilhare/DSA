class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mod  = 1e5;
        int maxProd = INT_MIN;
        int pre =1 , suf = 1;
        for(int i = 0 ; i< n ; i++){
            if(pre == 0) pre = 1;
            if(suf == 0) suf = 1;


            pre *= nums[i];
            suf *= nums[n-i-1];

            maxProd = max(max(pre, suf), maxProd);
        }

        return maxProd;
    }   
};