class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        vector<string>st;
        string temp = "";
        for(int i = 0 ; i< n ; i++){
            if(s[i]== ' '){
                
                if( !temp.empty()){
                    st.push_back(temp);
                    temp = "";
                }
            }
            else
            temp += s[i];
        }

        if(!temp.empty()) st.push_back(temp);
        string ans;
        for(int i = st.size()-1 ; i >= 0; i-- ){
            ans += st[i];
           if(i > 0) ans += " ";
        }

        return ans;
    }
};