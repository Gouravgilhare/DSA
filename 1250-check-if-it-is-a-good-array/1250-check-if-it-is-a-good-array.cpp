class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        
        //gCd of left side
        int hcf = nums[0];
        for(int i = 0 ; i< n ;i++){
            int g = gcd(hcf, nums[i]);
            if((1%g) ==0) return true;
            hcf = g;
        }


        return 0;


    }
};