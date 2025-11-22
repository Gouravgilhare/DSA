class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for(int n : nums){
            if(n%3!=0) cnt++;
        }

        return cnt;
    }
};