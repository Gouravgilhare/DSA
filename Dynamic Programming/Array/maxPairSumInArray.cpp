class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans= -1;
        vector<int>nums2(10,0);

        for(auto a : nums){
            
            int maxS = 0;

            int temp= a; 
            while(temp > 0){
                maxS= max( maxS, temp %10);
                temp /=10;
            }

            if(nums2[maxS] != 0){
                ans= max( nums2[maxS]+ a, ans);
            }
            if( a > nums2[maxS]){
                nums2[maxS] = a;
            }
        }
        return ans;
    }
};
