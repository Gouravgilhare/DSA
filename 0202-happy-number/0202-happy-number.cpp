class Solution {
public:
    bool isHappy(int n) {
        if(n<1) return false;
        if(n == 1 ) return true;
        unordered_set<int>st;
        
        while(n != 1 && st.find(n)==st.end()){
            st.insert(n);
            int sum = 0;
            while(n>0){
                int k = n % 10;
                sum += k*k;
                n /=10;
            }
            n = sum;

        }


        return n==1;
    }
};