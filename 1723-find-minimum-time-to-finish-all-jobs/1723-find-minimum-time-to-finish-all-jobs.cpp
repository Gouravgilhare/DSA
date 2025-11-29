class Solution {
public:
    int Min= INT_MAX;
    void helper(vector<int>&jobs, vector<int>&sum , int k, int j){
        int n = jobs.size();
        int Max= *max_element(sum.begin(),sum.end()); 

        if(Max >= Min) return ;

        if(j==n){
            Min  = min(Max, Min);
            return ;
        }

        for(int i = 0 ; i< k ; i++){
            if(i>0 && sum[i]==sum[i-1]){
                continue;
            }

            sum[i]+=jobs[j];
            helper(jobs, sum , k, j+1);

            sum[i]-=jobs[j];
        }

    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int>sum(k);
        helper(jobs,sum, k,0);

        return Min;
    }
};