class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int>freq;
        for(auto n : nums ){
            int rem = (n%value + value)%value;
            int f = freq[rem] | 0;
            freq[rem]= f+1;
        }

        int smallest  = INT_MAX;
        int remainder= 0;

        for(int i = 0 ;i< value; i++){
            int cnt = freq[i] | 0;
            if(cnt < smallest){
                smallest = cnt;
                remainder = i;
            }
        }

        return smallest * value + remainder;

    }
};