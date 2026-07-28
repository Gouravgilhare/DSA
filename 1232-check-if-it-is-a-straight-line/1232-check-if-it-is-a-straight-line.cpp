class Solution {
public:
    int helper(pair<int,int>p1, pair<int,int>p2, pair<int,int>p3 ){
        int x1 = p1.first , y1 = p1.second;
        int x2 = p2.first , y2 = p2.second;
        int x3 = p3.first , y3 = p3.second;
        return (y3-y2)*(x2-x1) - (y2-y1)*(x3-x2);
    }
    bool checkStraightLine(vector<vector<int>>& nums) {
        int n = nums.size();

        pair<int,int>p1 = {nums[0][0],nums[0][1]};
        pair<int,int>p2 = {nums[1][0],nums[1][1]};

        for(int i = 2 ; i< n ; i++){
            if(helper(p1,p2, {nums[i][0],nums[i][1]})!=0)
                return false;
        }

        return true;
    }
};