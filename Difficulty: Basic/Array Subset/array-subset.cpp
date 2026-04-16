class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        int n = a.size();
        int m = b.size();
        
        unordered_map<int, int>mp;
        
        for(auto i : a){
            mp[i]++;
        }
        
        for(int i = 0; i< m ; i++){
            if(mp.find(b[i])==mp.end()){
                return false;
            }
            
            mp[b[i]]--;
        
            if(mp[b[i]]==0){
                mp.erase(b[i]);
            }
        }
        
        return true;
    }
};