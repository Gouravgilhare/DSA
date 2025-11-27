class Solution {
public:
    bool canConstruct(string a, string b) {
        
        vector<int>arr(26,0);

        for(char i : b){
            arr[i-'a']++;
        }
        for(char i : a){
            arr[i-'a']--;
        }


        for(int i = 0 ; i< 26; i++){
            if(arr[i]<0) return false;
        }

        return true;
    }
};