class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool flag= false;
        int cnt = 0;
        for(int i = 0 ; i <= text.size(); i++){
            
            if(i < text.size() && text[i] != ' '){


                for(auto b : brokenLetters){
                    if(b == text[i]){
                        flag = true;
                        break;
                    }

                }
            }else {
                if(!flag){
                    cnt++;
                }
                flag = false;
            }
        }  
        return cnt;
    }
};