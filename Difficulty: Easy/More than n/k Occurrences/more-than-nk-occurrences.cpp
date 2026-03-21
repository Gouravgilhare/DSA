class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Your code here
        long long n = arr.size();
        unordered_map<long long,int>mp;
        int  t = n/k;
        for(auto it : arr){
            mp[it]++;
        }
        
        
        int cnt = 0 ;
        for(auto it : mp){
            if(it.second > t) {
                cnt++;
            }
        }
        
        
        return cnt;
    }
};