class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;

        int ans = 9 , finalAns = 10, avail= 9;

        for(int i = 2; i<= n ; i++){
            ans *= avail;
            finalAns += ans;
            avail--;
        }

        return finalAns;
    } 
};