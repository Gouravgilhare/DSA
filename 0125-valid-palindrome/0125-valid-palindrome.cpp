class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        string a = "";

        for(int i = 0 ;i<n ;i++){

            if(isalnum(s[i]))
            a += tolower(s[i]);
        
        }

        n =a.size();
        for(int i = 0 ; i <a.size()/2; i++){
            if(a[i] != a[n-1-i]) return false;
        }

        return true;
    }
};