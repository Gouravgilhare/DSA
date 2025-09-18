class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int maxI = 0, maxE= nums[0];
        for(int i = 0 ; i< nums.size(); i++){
            if(maxE < nums[i]){
                maxE =  nums[i];
                maxI = i;
            }

        }
        return maxI;
    }
};