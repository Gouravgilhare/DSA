class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {

        vector<string>ans;
        ans.push_back(words[0]);

        for(int i = 1; i< words.size(); i++){
            if(!checkAnagram(words[i],words[i-1])){
                ans.push_back(words[i]);
            }
        }   

        return ans;
    }
    bool checkAnagram(string a, string b){
        int arr[26]={0};
        if(a.size()!= b.size()) return false;
        for(int i = 0 ; i < a.size(); i++){
            arr[a[i]-'a']++;
            arr[b[i]-'a']--;
        }
        int flag= 0;
        for(int i = 0 ; i<26;i++){
            if(arr[i]!=0) {
                return false;
            }
        }

        return true;
    }
};