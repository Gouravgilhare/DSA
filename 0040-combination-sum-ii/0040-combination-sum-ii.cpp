class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void helper(vector<int>&candidates, int target, int index,int sum){
        int n =  candidates.size();
        // if(index == n) return;
        if(target == sum) {
            ans.push_back(temp);
            return ;
        }    

        if(sum > target) return;

        for(int i = index; i<n ;i++){

            if(i>index && candidates[i]== candidates[i-1]) continue;
            temp.push_back(candidates[i]); 
            helper(candidates,target, i+1, sum+candidates[i]);
            temp.pop_back();
            // helper(candidates,target, index+1, sum);

        }


        return ;    

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0,0);

        return ans;
    }
};