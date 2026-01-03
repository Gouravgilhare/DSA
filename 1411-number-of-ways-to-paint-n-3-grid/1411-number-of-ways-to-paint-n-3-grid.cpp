class Solution {
public:
    int numOfWays(int n) {
        long aba = 6; // Initial row patterns of type ABA
        long abc = 6; // Initial row patterns of type ABC
        long mod = 1e9 + 7;

        for (int i = 1; i < n; ++i) {
            long prev_aba = aba;
            long prev_abc = abc;

            // Transition formulas
            aba = (3 * prev_aba + 2 * prev_abc) % mod;
            abc = (2 * prev_aba + 2 * prev_abc) % mod;
        }

        return (aba + abc) % mod;
    }
};