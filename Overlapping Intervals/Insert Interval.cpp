// Title: Insert and Merge Intervals  
// Difficulty: Medium  

// Problem:  
// You are given a list of non-overlapping intervals, where each interval is a pair of integers [start, end] representing the start and end of an interval. The intervals are not necessarily sorted.

// You are also given a new interval `newInterval` to insert into the list.  
// Your task is to insert `newInterval` into the existing list of intervals and merge all overlapping intervals.  

// The resulting list should contain no overlapping intervals, and the merged list should be sorted in descending order by the start time.

// Function Signature (C++):  
// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval);

// Constraints:
// - 0 <= intervals.length <= 10⁴  
// - intervals[i].size() == 2  
// - 0 <= intervals[i][0] <= intervals[i][1] <= 10⁴  
// - 0 <= newInterval[0] <= newInterval[1] <= 10⁴  

// Example 1:  
// Input:  
// intervals = [[1,3],[6,9]]  
// newInterval = [2,5]  
// Output:  
// [[6,9],[1,5]]  

// Explanation:  
// [1,3] and [2,5] overlap and are merged into [1,5]. [6,9] remains unchanged.  
// The result is sorted in descending order by start time.

// Example 2:  
// Input:  
// intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]  
// newInterval = [4,8]  
// Output:  
// [[12,16],[3,10],[1,2]]  

// Explanation:  
// [3,5], [6,7], and [8,10] overlap with [4,8], and are merged into [3,10].


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>merge;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(), [](const vector<int>&a, const vector<int>&b){
            return a[0] < b[0];
        });        
        vector<int>temp = intervals[0];
        for(const auto& interval : intervals){
            if(interval[0] <= temp[1]){
                temp[1] = max(interval[1], temp[1] );
            }
            else{
                merge.push_back(temp);
                temp= interval;
            }
        }
        merge.push_back(temp);
        return merge;
    }
};

// Note:  
// - You must merge intervals that overlap after inserting the new interval.  
// - The final output should be sorted in descending order by the start of each interval.
