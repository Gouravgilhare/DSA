// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2



class Solution {
public:
    int jump(vector<int>& nums) {
        
        int jump=0,l=0,r=0;
        while( r < nums.size()-1){
            int farthest = 0 ; 
             for(int  i = l ; i<=r; i++){
                farthest = max( i+nums[i], farthest);
             }
            l = r+1; 
            r= farthest;
            jump++; 
        }

        return jump;
    }
};



//Optimal solution


// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 1) return 0;  // No jumps needed if only one element.

//         int jumps = 0;
//         int farthest = 0;
//         int current_end = 0;

//         for (int i = 0; i < n; ++i) {
//             farthest = max(farthest, i + nums[i]);  // Calculate the furthest reachable index.

//             // If we have reached the end of the range for the current jump
//             if (i == current_end) {
//                 jumps++;  // Increment the jump count.
//                 current_end = farthest;  // Update the range we can reach with the current jump.

//                 // If we can reach or exceed the last index, we're done
//                 if (current_end >= n - 1) break;
//             }
//         }

//         return jumps;
//     }
// };
