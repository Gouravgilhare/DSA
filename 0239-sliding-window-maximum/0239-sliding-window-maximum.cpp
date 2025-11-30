class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>ans;

        deque<int>dq;

        for(int i =0 ; i< k; i++){

            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        // vector<int>ans;
        for(int i=k ; i<n ; i++){
            ans.push_back(nums[dq.front()]);

            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()]<= nums[i])
                dq.pop_back();


                dq.push_back(i);
            // dp.push(i);
        }


        if(!dq.empty())
            ans.push_back(nums[dq.front()]);
        return ans;
        
    }
};