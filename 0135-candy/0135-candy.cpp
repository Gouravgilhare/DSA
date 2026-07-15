class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> minCandy(n,1);
        //look from left
        for(int i = 0 ; i< n ; i++){
            if(i-1>= 0 && ratings[i-1] < ratings[i]){
                minCandy[i] = max(minCandy[i], minCandy[i-1] + 1);
            }
        }

        //look from right
        for(int i = n-1; i > -1; i--){
            if(i+1 < n  && ratings[i] > ratings[i+1]){
                minCandy[i] = max(minCandy[i], minCandy[i+1]+1);
            }
        }
        
        //sum 
        int count= 0;
        for(auto a : minCandy){
            count +=a;
        }

        return count;
    }
};