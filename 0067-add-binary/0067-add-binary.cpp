class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size(), m = b.size();
        string c;
        int carry = 0;
        int  i= n-1, j = m- 1;
        while(i >=0  || j>=0 || carry   ){
            int sum = carry;

            if(i>=0) sum+=a[i--]-'0';
            if(j>=0) sum+=b[j--]-'0';

            c += sum%2 + '0';
            carry = sum/2;        
            }


        
        reverse(c.begin(),c.end());
        return c;
    }
};