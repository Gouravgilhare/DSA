class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<int>users = skill;
        vector<int>products = mana;

        int m = products.size();
        int n = users.size();
        vector<long>times(n,0);

        for(int i = 0 ; i< m ; i++){
            for(int j = 0 ; j < n ; j++){
                long t = products[i]*users[j];

                if(j == 0 ){
                    times[0] += t;
                }else{
                    times[j] = max(times[j], times[j-1])+ t;
                }
            }

            for(int j = n-2; j>= 0 ; j--){
                times[j] = times[j+1] - products[i]*users[j+1];
            }
        }


        return times[n-1];
        
    }
};