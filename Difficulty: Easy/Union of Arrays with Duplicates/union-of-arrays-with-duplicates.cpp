class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int, int>mp;
        
        
        for(int i= 0 ; i<a.size(); i++){
            mp[a[i]]++;
            
        }
        for(int i= 0 ; i<b.size(); i++){
            mp[b[i]]++;
        }
        
        vector<int>ans;
        for(auto it = mp.begin()  ;  it != mp.end() ; it++){
            
            if(it->second > 0 )ans.push_back(it->first);
        }
        
        return ans;
    }
};