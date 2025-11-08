class Solution {
public:
    void combSum(int i, vector<int>& arr, vector<int>& combi, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(combi);
            return;
        }
        if (i == arr.size() || target < 0) return;

        // pick the current element
        combi.push_back(arr[i]);
        combSum(i, arr, combi, ans, target - arr[i]); // stay at i
        combi.pop_back();

        // skip the current element
        combSum(i + 1, arr, combi, ans, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combi;
        vector<vector<int>> ans;
        combSum(0, candidates, combi, ans, target);
        return ans;
    }
};
