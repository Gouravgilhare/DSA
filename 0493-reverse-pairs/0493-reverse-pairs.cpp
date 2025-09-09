class Solution {
public:
    int mergesort(vector<int>&nums, int l, int r){
        if( l >= r ) return 0;
        int mid = (l+r)/2;
        int cnt = mergesort(nums,l, mid) + mergesort(nums, mid+1, r);

        int j = mid +1;
        for(int i = l ; i <= mid; i++){
            while(j <= r && (long long)nums[i] > 2LL * nums[j]) j++;
            cnt += j - (mid +1 );
        }

        vector<int> temp;
        int i = l   ; j = mid+1;
        while(i <= mid && j <=r){
            if(nums[i]<= nums[j])temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while(i<= mid) temp.push_back(nums[i++]);
        while(j<= r) temp.push_back(nums[j++]);

        for(int k = 0 ; k <temp.size(); k++){
            nums[k+l] = temp[k];
        }

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
       return mergesort(nums, 0, nums.size()-1);
    }
};