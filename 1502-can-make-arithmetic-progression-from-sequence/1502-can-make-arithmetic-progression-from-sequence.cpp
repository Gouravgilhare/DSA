class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();

        int minE = INT_MAX , maxE = INT_MIN;
        for(auto a : arr){
            minE = min(minE, a);
            maxE = max(maxE, a);
        }
        if((maxE-minE)%(n-1) != 0) return false;
        int d= (maxE-minE)/(n-1);
        int i = 0 ;
        while(i<n){
            int num = arr[i];

            if(num == minE + i*d) i++;
            else{
                if((num - minE)%d != 0) return false;
                int j = (num - minE)/d;

                if(num == arr[j]) return false;

                swap(arr[i], arr[j]); 
            }
        }

        return true;
    }
};