class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen=0;
        int r = 0, l=0;
        unordered_map<int,int>mp;

        while(r<n){
            mp[fruits[r]]++;

            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]]==0) mp.erase(fruits[l]);
                    l++;
                }
            }
            if(mp.size()<=2){
                maxLen= max(maxLen ,r-l+1);
            }
            r++;
        }
        
        return maxLen;
    }
};