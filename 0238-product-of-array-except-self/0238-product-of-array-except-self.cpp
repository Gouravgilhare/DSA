class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int cnt = 0;

        for(auto a : nums){
            if(a ==0) cnt++;
            else prod *= a;
        }

        vector<int>arr;
        for(auto a : nums){
            if(a == 0  && cnt > 1){
                arr.push_back(0);
            }else if(a== 0 && cnt == 1){
                arr.push_back(prod);
            }
            else if(a!=0 && cnt > 0) {
                arr.push_back(0);
            }else{
                arr.push_back(prod/a);
            }
        }


        return arr;
    }
};