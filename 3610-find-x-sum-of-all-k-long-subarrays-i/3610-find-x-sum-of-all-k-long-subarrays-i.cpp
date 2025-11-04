class Solution {
public:

    int calculateSum(unordered_map<int,int>&mp, int x){
        vector<pair<int,int>>vec(mp.begin(),mp.end());
        
        sort(vec.begin(),vec.end(),[](const pair<int,int>&a, const pair<int,int>&b) {
            if(a.second ==b.second) return a.first > b.first;

            return a.second > b.second;
        
        });

        int cnt= 0, sum =0;
        for(auto it : vec){
            if(cnt >= x){
                break;
            }
            sum += it.first * it.second;
            cnt++;
        }

        return sum;

    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans(n-k+1,0);
        unordered_map<int,int>mp;
        for(int i = 0 ; i< k ; i++){
            mp[nums[i]]++;
        }

        ans[0]=calculateSum(mp,x);

        for(int i = k; i<n ; i++){
            int newEle = nums[i];
            int oldEle = nums[i-k];

            mp[newEle]++;
            if(--mp[oldEle]==0)
                mp.erase(oldEle);
            
            ans[i-k+1]= calculateSum(mp,x);
        }

        return ans;
    }
};