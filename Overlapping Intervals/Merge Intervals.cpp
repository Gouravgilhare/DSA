// Title: Merge Overlapping Intervals  
// Difficulty: Medium  

// Problem:  
// Given an array of intervals where each interval is represented as a pair of integers [start, end], merge all overlapping intervals and return an array of the merged intervals.

// Two intervals [a, b] and [c, d] are considered overlapping if c <= b.  
// The final list of merged intervals should be sorted in ascending order based on their start times.

// Function Signature (C++):  
// vector<vector<int>> merge(vector<vector<int>>& intervals);

// Constraints:
// - 1 <= intervals.length <= 10⁴  
// - intervals[i].size() == 2  
// - 0 <= intervals[i][0] <= intervals[i][1] <= 10⁴  
// - Intervals are not necessarily sorted  

// Example 1:  
// Input:  
// intervals = [[1,3],[2,6],[8,10],[15,18]]  
// Output:  
// [[1,6],[8,10],[15,18]]  
// Explanation:  
// Intervals [1,3] and [2,6] overlap and are merged into [1,6].

// Example 2:  
// Input:  
// intervals = [[1,4],[4,5]]  
// Output:  
// [[1,5]]  
// Explanation:  
// Intervals [1,4] and [4,5] overlap since 4 ≤ 4, so they are merged into [1,5].

// Example 3:  
// Input:  
// intervals = [[1,4],[0,2],[3,5]]  
// Output:  
// [[0,5]]  
// Explanation:  
// All intervals overlap and are merged into one.

// Note:  
// To solve this efficiently:
// 1. Sort the intervals based on the starting time.  
// 2. Traverse through the sorted list and merge overlapping intervals using a temporary interval that tracks the current merging range.



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

      if(intervals.size() == 1) return intervals;

    //   Sort intervals based on the starting time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<int> temp = intervals[0];
        vector<vector<int>>m;
      for(const auto& a : intervals) 
        {
            if(a[0] <= temp[1]){
                    temp[1]=max(a[1], temp[1]);
            }else{
                m.push_back(temp);
                temp = a;
            }
        }

        m.push_back(temp);

        return m;
    }
};
