class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long>freq;
        for(auto p : power) freq[p]++;

        vector<long long> vals;
        for(auto [v,f] : freq){
            vals.push_back(v);
        }

        sort(vals.begin(),vals.end());

        int n = vals.size();
        vector<long long> dp(n);

        dp[0]= vals[0]*freq[vals[0]];

        for(int i = 1 ; i < n;++i){
            long long take = vals[i]*freq[vals[i]];

            int j = upper_bound(vals.begin(),vals.end(),vals[i]-3 )-vals.begin() -1;

            if(j >= 0) take +=dp[j];

            long long skip = dp[i-1];
            dp[i] = max(skip, take);


        }
            return dp[n-1];
    }
};