class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        int square[n+1];
        int left ,sum , i, right;

        for(i  = 0 ; i<=n ; ++i){
            square[i] = i*i;
            left = 0;
            right = i-1;
            while(left<right){
                sum = square[left]+square[right];
                if(sum == square[i]){
                    cnt+=2;
                    ++left;
                    continue;
                }
                if(sum<square[i]){
                    // count += 2;
                    ++left;
                    continue;
                }
                --right;
            }
        }


        return cnt;
    }
};