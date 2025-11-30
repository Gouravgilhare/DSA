class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        int sum = 0;

        for(int &num : nums){
            sum= (sum+num)%p;
        }

        //(a+b)%p == (a%p + b%p)%p

        int target = sum%p;
        if(target == 0  )return 0;

        unordered_map<int,int>mp;

        int result = n;
        mp[0]=-1;
        int currSum = 0;
        for(int i = 0 ; i<n ; i++){

            currSum = (currSum + nums[i])%p;

            int remain  = (currSum -target +p )%p;

            if(mp.find(remain)!= mp.end()){
                result = min( i -mp[remain], result); 
            }

            mp[currSum] = i; 


        }
            return result == n? -1: result;
    }
};