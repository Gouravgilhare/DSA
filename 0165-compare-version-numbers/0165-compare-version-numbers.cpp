class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();
        
        while (i < n1 || j < n2) {
            // extract next token from version1
            int start1 = i;
            while (i < n1 && version1[i] != '.') ++i;
            string t1 = (start1 < i) ? version1.substr(start1, i - start1) : "0";
            if (i < n1 && version1[i] == '.') ++i; // skip '.'
            
            // extract next token from version2
            int start2 = j;
            while (j < n2 && version2[j] != '.') ++j;
            string t2 = (start2 < j) ? version2.substr(start2, j - start2) : "0";
            if (j < n2 && version2[j] == '.') ++j; // skip '.'
            
            // strip leading zeros
            int p1 = 0; while (p1 < (int)t1.size() && t1[p1] == '0') ++p1;
            int p2 = 0; while (p2 < (int)t2.size() && t2[p2] == '0') ++p2;
            string s1 = (p1 < (int)t1.size()) ? t1.substr(p1) : "0";
            string s2 = (p2 < (int)t2.size()) ? t2.substr(p2) : "0";
            
            // compare by length first (big-int compare)
            if (s1.size() > s2.size()) return 1;
            if (s1.size() < s2.size()) return -1;
            // same length -> lexicographical compare
            if (s1 > s2) return 1;
            if (s1 < s2) return -1;
            // otherwise equal, continue to next tokens
        }
        return 0;
    }
};
