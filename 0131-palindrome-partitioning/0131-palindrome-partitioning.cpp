class Solution {
public:
    bool isPalin(string s, int i, int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }

        return true;
    }
    void palin(int i,vector<string>&ss, string s,  vector<vector<string>>&ans){
        if(i==s.size()) {
            ans.push_back(ss);
            return;
        }
        
        for(int j = i ; j<s.size();++j){
            if(isPalin(s, i, j)){
                ss.push_back(s.substr(i, j-i+1));
                palin(j+1,ss,s,ans);
                ss.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ss;

        palin(0,ss,s,ans);

        return ans;
    }
};