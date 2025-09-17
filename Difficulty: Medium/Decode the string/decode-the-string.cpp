class Solution {
  public:
    string decodedString(string &s) {
        stack<int> numStack;
        stack<string> strStack;
        string currStr = "";
        int num = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0'); // build multi-digit number
            } 
            else if (ch == '[') {
                numStack.push(num);
                strStack.push(currStr);
                num = 0;
                currStr = "";
            } 
            else if (ch == ']') {
                int repeatTimes = numStack.top(); numStack.pop();
                string prevStr = strStack.top(); strStack.pop();
                
                string expanded = "";
                for (int i = 0; i < repeatTimes; i++) {
                    expanded += currStr;
                }
                currStr = prevStr + expanded;
            } 
            else {
                currStr += ch; // normal character
            }
        }
        return currStr;
    }
};
