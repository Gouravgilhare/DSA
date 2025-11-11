class Solution {
public:
    void swd(vector<int>&nums, vector<vector<int>>&ans,vector<int>&a,int i ){
        // if( i == nums.size()) return;

        ans.push_back(a);


        for(int j = i ; j< nums.size(); j++){


            if(j > i && nums[j]==nums[j-1]) continue;
        
        a.push_back(nums[j]);   
        swd(nums,ans,a,j+1);
        a.pop_back();   
        // swd(nums,ans,a,i+1);
        
        }


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
           vector<vector<int>>ans;
                   vector<int>a;
            sort(nums.begin(), nums.end());
            // ans.push_back(a);
           swd(nums,ans,a,0);

           return ans;
    }
};