class Solution {
public:
    int addDigits(int num) {
        while(num){
            if(num<10){
                return num;
            }
            int add= 0;
            int n = num;
            while(n){
                int t = n%10;
                add += t;
                n /=10;
            }
            num=add;
        }

        return num;
    }
};