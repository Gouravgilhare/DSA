class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>>a;
        int n = nums.size();
        for(int i = 0 ; i <n ; i++ ){
            a.push_back({nums[i], i});
        }


        sort(a.begin(), a.end());
        int left = 0, right = n-1;

        while(left < right){
            int sum = a[left].first + a[right].first;

            if(sum == target) return {a[left].second, a[right].second};

            if(sum < target) left++;
            else right--;

        }

        return {-1, -1};
    }
};