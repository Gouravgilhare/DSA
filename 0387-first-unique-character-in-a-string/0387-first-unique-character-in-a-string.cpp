class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26, 0);

        stack<int>st;
        
        for(auto c :s){
            freq[c-'a']++;
        }
    
        for(int i = 0 ; i< s.size() ; i++){
            
            if(freq[s[i]-'a']==1){
                st.push(i);
            }
        }

        if(st.empty()) return -1;
        int ans = INT_MAX;
        while(!st.empty()){
            

            ans = min(ans, st.top());
            st.pop();
        }

        
        return ans;
    }
};