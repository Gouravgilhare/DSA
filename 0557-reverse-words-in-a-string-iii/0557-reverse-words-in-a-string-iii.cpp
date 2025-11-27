class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ') 
                i++;  // skip spaces
            
            int j = i;

            while (j < n && s[j] != ' ')
                j++;  // find end of word

            // reverse the word from i to j-1
            reverse(s.begin() + i, s.begin() + j);

            i = j;
        }

        return s;
    }
};
