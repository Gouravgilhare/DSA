class Solution {
public:
    double myPow(double x, int m) {
        // if(n == 0) return 1.0;
        // if(x == 0) return 0.0;
        // if(x == 1) return 1.0;
        // if(x== -1 && n%2!= 0) return -1.0;
        // if(x== -1 && n%2== 0) return 1.0;
        long long n = m;
       if(n <0){
        x= 1/x;
        n = -n;
       }
        double ans = 1;
        while(n > 0){   
            if(n%2==1){
                ans *= x;
                
            }
                x *= x;
                n/=2;
            
        }
        return ans;
    }
};