class Solution {
public:
    vector<string>temp;
    vector<vector<string>>ans;

    bool isPalin(string s){
        int n = s.size();

        int left =0; 
        int right =n-1;

        while(left<right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }

        return true;
    }


    void helper(string s, int index){
        int n = s.size();
        if(index== n) {
            ans.push_back(temp);
            return;
        }

        string t ="";
       for(int i = index; i< n; i++){
            t += s[i];

            if(isPalin(t)){
                temp.push_back(t);
                helper(s,i+1);
                temp.pop_back();            
            }

       }

    
    }
    vector<vector<string>> partition(string s) {
         helper(s,0);

         return ans;
    }
};