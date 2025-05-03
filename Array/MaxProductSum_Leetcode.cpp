class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int leftproduct =1;
        int size = nums.size();
        int rightproduct =1;
        int ans=nums[0];

        for (int  i =0 ; i<size; i++){

            leftproduct = (leftproduct == 0 )? 1: leftproduct;
            rightproduct = (rightproduct == 0 )? 1: rightproduct;

            leftproduct *= nums[i];
            rightproduct *= nums[size - i-1];  
            ans = max( ans, max(leftproduct, rightproduct));

        }
            

            return ans;
    }
};
