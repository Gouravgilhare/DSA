class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        int ans = 0;

        int mini = arrays[0][0];
        int maxi = arrays[0].back();

        for (int i = 1; i < arrays.size(); i++) {

            ans = max(ans, arrays[i].back() - mini);
            ans = max(ans, maxi - arrays[i][0]);

            mini = min(mini, arrays[i][0]);
            maxi = max(maxi, arrays[i].back());
        }

        return ans;
    }
};