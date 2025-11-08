class Solution {
public:

    void combSum(int i, vector<int>&arr, vector<int>&com, vector<vector<int>>&ans, int target){
        if(target == 0) {
            ans.push_back(com);
            return;
        }

        if(i == arr.size() || target < 0) return;

        com.push_back(arr[i]);
        combSum(i+1, arr, com, ans, target-arr[i]);

        com.pop_back();
        int next = i+1;
        while(next<arr.size() && arr[next]==arr[i])next++;
        combSum(next, arr, com, ans, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>com;

        sort(arr.begin(), arr.end());

        combSum(0,arr, com, ans, target);

        return ans;
    }
};