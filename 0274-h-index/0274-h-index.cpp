class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int i = 1 ; 
        while(i<=n){
            if(citations[n-i] < i)
                break;
            i++;
        }
        return i-1;
    }
};