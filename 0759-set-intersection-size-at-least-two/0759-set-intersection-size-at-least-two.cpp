class Solution {
public:

    static bool check(vector<int>a, vector<int>b){
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        return a[1]<b[1];
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), check);
        int count = 2;
        vector<int>maxi(2,0);
        maxi[0]=intervals[0][1]-1;
        maxi[1]=intervals[0][1];

        for(int i = 0; i<n ;i++){
            if(maxi[1]<intervals[i][0]){
                count += 2;
                maxi[0]=intervals[i][1]-1;
                maxi[1]=intervals[i][1];

            }else if(maxi[0]<intervals[i][0]){
                count++;
                maxi[0]=maxi[1];
                maxi[1]=intervals[i][1]; 
            }
        }
        return count;
    }
};