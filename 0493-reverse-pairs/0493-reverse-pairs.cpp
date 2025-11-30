class Solution {
public:

    int mergePairs(vector<int>&nums, int l, int mid, int r){
        int cnt= 0;
        int i = l ; 
        int j = mid+1;
        while(i<=mid && j<=r){
            if(i<j && nums[i] > 2LL*nums[j]){
                // cnt++;
                cnt+= mid-i +1;
                j++;
            }else{
                i++;
            }
        }


        return cnt;
    }

    void merge(vector<int>&nums, int l, int mid, int r){
        
        vector<int>temp;
        int i = l, j = mid+1;
        while(i<= mid && j<=r){

            if(  nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;

            }
        }

        while(j<=r){
                temp.push_back(nums[j++]);

        }

        while(i<=mid){
                temp.push_back(nums[i++]);

        }

        for(int i = 0 ; i<temp.size();  i++){
            nums[l+i]= temp[i];
        }


        return ;
    }
    int mergeSort(vector<int>&nums, int l, int r){
        if(l>=r)return 0;
        int cnt= 0;
        int mid =l+ (r-l)/2;
        cnt += mergeSort(nums, l , mid);
        cnt += mergeSort(nums, mid+1 , r);
        cnt += mergePairs(nums, l, mid , r);

        merge(nums, l, mid, r);

        return cnt;

    }


    int reversePairs(vector<int>& nums) {
        
        return mergeSort(nums, 0, nums.size()-1);
    }
};