class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left(n),right(n);
        int mx= 0;
        for(int i = 0 ; i< n ; i++){
            mx = max(mx, height[i]);
            left[ i ] = mx;
        }   
        mx= 0;
        for(int j = n-1; j >=0 ;j--){
            mx = max(height[j], mx);
            right[j] = mx;
        }

        int ans = 0;
        for(int i = 0 ; i <n ; i++){
            ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};