class Solution {
public:

    typedef long long ll;
bool possible(vector<int>& batteries, long long mid, int n) {
    long long total = 0;

    for (auto b : batteries) {
        total += min((long long)b, mid);
    }

    return total >= mid * n;
}
    long long maxRunTime(int n, vector<int>& batteries) {

        ll l = *min_element(batteries.begin(), batteries.end());
        
        ll sum_total_minutes = 0;
        for(auto &min : batteries){
            sum_total_minutes += min;
        }


        ll r= sum_total_minutes/n;

        ll result = 0;

        while(l<=r){
            ll mid = l + (r-l)/2;

            if(possible(batteries, mid, n)){
                result = mid;
                l =mid+1;
            }else{

                r= mid-1;  
            }
        }
        return result;

    }
};