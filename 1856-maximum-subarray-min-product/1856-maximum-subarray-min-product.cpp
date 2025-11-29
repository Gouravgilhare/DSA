class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        vector<long long>prefix(n+1,0);

        for(int i =0 ; i< n ; i++){
            prefix[i+1] = prefix[i] +nums[i];
        }

        vector<int>left(n),right(n);

        stack<int>st;

        for(int i = 0 ;i<n; i++){
            
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }


            if(!st.empty())
            left[i] = st.top();
            else
            left[i] = -1;

            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n-1; i>=0 ;i--){

            while(!st.empty() && nums[st.top()] > nums[i])st.pop();

            right[i] = (st.empty()?n: st.top());

            st.push(i);
        }

        long long ans =  0, mod=1e9+7;

        for(int i = 0 ; i< n ; i++){

            long long l = left[i]+1;
            long long r = right[i]-1;

            long long subSum = prefix[r+1]- prefix[l];
            long long prod = subSum*nums[i];

            ans =max(ans, prod);
        }


        return ans%mod;

    }
};