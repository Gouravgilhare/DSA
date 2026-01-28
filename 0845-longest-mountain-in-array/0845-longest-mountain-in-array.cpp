class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        if(arr.size() < 3) return 0;
        int n = arr.size();
        int ans = 0;
        
        for(int i =1; i< n-1; i++){

            if(arr[i-1] < arr[i] && arr[i] > arr[i+1]){
                int left=i-1;
                int right= i+1;

                //check left
                while(left > 0 && arr[left] > arr[left-1])
                    left--;
                
                //check right
                while(right < n-1 && arr[right] > arr[right+1])
                    right++;

                ans = max(ans, right-left+1);
            }


        }

        return ans;



    }
};