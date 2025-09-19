class Solution {
  public:
    int minParentheses(string& s) {
        // code here
        
        int open = 0; int insertion= 0;
        for(int i = 0 ; i<s.size(); i++){
            if(s[i] == '(')
                open++;
            else
                {
                    if(open > 0) open--;
                    else insertion++;
                }
        }
        
        
        return insertion+ open;
        
    }
};