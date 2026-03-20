class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        if(n==0) return 0;
        
        int longest = 1;
        unordered_set<int>st;
        for(int i = 0 ; i< n ; i++){
            st.insert(arr[i]);
        }
        
        int cnt =1;
        
        for(auto  it : st){
            
            if(st.find(it-1) == st.end()){
                cnt = 1;
                int x= it;
                while(st.find(x+1) != st.end()){
                    cnt++;
                    x++;
                }
                longest = max(cnt, longest);
            }
        }
        
        
        return longest;
        
    }
};