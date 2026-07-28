class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        int minE = INT_MAX , maxE = INT_MIN;
        unordered_set<int>st;
        for(auto a : arr){
            minE = min(minE, a);
            maxE = max(maxE, a);
            st.insert(a);
        }
        if((maxE-minE)%(n-1) != 0) return false;
        int d= (maxE-minE)/(n-1);
        int i = 0 ;
        while(i<n){
            int num = minE + (i)*d;
            if(st.find(num) == st.end()) return false;
            i++;
        }

        return true;
    }
};