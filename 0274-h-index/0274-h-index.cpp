class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        // sort(citations.begin(), citations.end());
        vector<int>bucket(n+1, 0);

        for(int k : citations){
            if(k>=n)
            bucket[n]++;
            else
            bucket[k]++;
        }
        
        int total = 0;
        int i ;
        for( i = n ; i>=0 ; i--){

            total+=bucket[i];

            if(total >= i)break;
        }

        return i;
    }
};