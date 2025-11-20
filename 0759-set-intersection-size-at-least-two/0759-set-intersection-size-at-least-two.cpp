class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](auto & a , auto& b) {
            return a[1] < b[1] || (a[1]==b[1] && a[0]>b[0]);
        });

        int ans = 0 , p1=-1, p2=-1;
        for(auto x : intervals) {
            if(x[0] <= p1) continue;

            if(x[0] > p2) {
                ans+=2;
                p2 = x[1];
                p1 = p2-1;
            }
            else {
                ans+=1;
                p1 = p2;
                p2 = x[1];
            }
            // cout<<"p1: " << p1 <<", p2: " << p2 <<" ans: " << ans << endl;
        }

        return ans;
        
    }
};