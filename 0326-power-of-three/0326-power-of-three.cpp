class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <=0) return false;
        long long power = pow(3,19);

        return (power%n) == 0;
        
    }
};