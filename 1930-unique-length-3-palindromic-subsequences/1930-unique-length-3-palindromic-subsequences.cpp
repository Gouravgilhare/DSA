class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int first[26], last[26];
        int n = s.size();
        
        fill(first, first + 26, -1);
        fill(last, last + 26, -1);

        // find first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (first[c] == -1)
                first[c] = i;
            last[c] = i;
        }

        int count = 0;

        // for each character 'a' to 'z'
        for (int c = 0; c < 26; c++) {
            if (first[c] != -1 && last[c] != -1 && last[c] > first[c]) {
                
                // find unique chars in the middle
                unordered_set<char> mid;
                
                for (int k = first[c] + 1; k < last[c]; k++) {
                    mid.insert(s[k]);
                }

                count += mid.size();  // each gives a palindrome c _ c
            }
        }

        return count;
    }
};
