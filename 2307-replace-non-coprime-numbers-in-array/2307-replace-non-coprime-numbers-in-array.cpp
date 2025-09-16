class Solution {
public:
    long long _gcd(long long  a, long long b){
        if(b == 0) return a;

        return _gcd(b, a%b);
    }
    bool checkNonCoPrime(long long  a, long long b){
        long long gcd = _gcd(a,b);
        if(gcd > 1) return true;
        return false;
    }
    long long  LCM(long long  a, long long b){
        return (a*b)/_gcd(a,b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        vector<long long>st;

        for(auto num : nums ){

            st.push_back(num);

            while(st.size() > 1 && checkNonCoPrime(st[st.size()-2], st[st.size()-1])){
                long long a = st[st.size() -2];
                long long b = st[st.size() -1];
                long long g = _gcd(a,b); 
                
                if(g == 1 ) break;

                st.pop_back();
                st.pop_back();
                st.push_back(LCM(a,b));
            }

        }
        vector<int>ans(st.begin(), st.end());
       
       return ans;
    }

};