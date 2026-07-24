class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        arr.push_back(1);
        //prefixx
        for(int i = 1 ; i < n ;  i++){
            arr.push_back(arr[i-1] * nums[i-1]);
        }

        //suffixx
        int suff = 1;
        for(int i = n-2 ; i >=0 ; i--){
            suff *= nums[i+1];
            arr[i] = arr[i] *suff;
        }


        return arr;

    }
};