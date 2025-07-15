// Title: Find the Duplicate Number

// Difficulty: Medium/Hard

// Problem:
// Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, there is exactly **one duplicate number** in the array.

// Your task is to **find and return the duplicate number**.

// You must **not modify** the array and must use **constant extra space** and **less than O(n²)** time complexity.

// ---

// Function Signature (C++):
// int findDuplicate(vector<int>& nums);

// ---

// Constraints:
// - 1 <= nums.length <= 10⁵
// - nums contains `n + 1` integers, where each integer is in the range `[1, n]`.
// - There is only **one repeated number**, but it could be repeated more than once.
// - You **cannot modify the array** (e.g., by sorting it).
// - You must use **only constant extra space**.

// ---

// Example 1:

// Input:
// nums = [1,3,4,2,2]

// Output:
// 2

// Explanation:
// 2 is the only number that appears more than once.

// ---

// Example 2:

// Input:
// nums = [3,1,3,4,2]

// Output:
// 3

// Explanation:
// 3 appears twice.

// ---

// Example 3:

// Input:
// nums = [1,1]

// Output:
// 1

// Explanation:
// The only number repeated is 1.

// ---

// Example 4:

// Input:
// nums = [1,1,2]

// Output:
// 1

// ---

// Example 5:

// Input:
// nums = [2,5,9,6,9,3,8,9,7,1]

// Output:
// 9

// ---

// Note:
// This algorithm treats the values as **linked list pointers** and detects a cycle caused by the duplicate.


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow= nums[slow];
            fast= nums[fast];
        }

        return slow;

        
    }
};
