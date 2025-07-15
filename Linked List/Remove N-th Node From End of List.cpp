// Title: Remove N-th Node From End of List

// Difficulty: Medium

// Problem:
// Given the head of a singly linked list, remove the n-th node from the end of the list and return its head.

// You must solve it in one pass using O(1) extra space.

// Constraints:
// - The number of nodes in the list is in the range [1, 10^4].
// - 1 <= Node.val <= 10^5
// - 1 <= n <= number of nodes in the list

// ------------------------------------------------------------------------------

// Function Signature (C++):
// ListNode* removeNthFromEnd(ListNode* head, int n);

// ------------------------------------------------------------------------------

// Example 1:

// Input:
// head = [1, 2, 3, 4, 5]
// n = 2

// Output:
// [1, 2, 3, 5]

// Explanation:
// The 2nd node from the end (value 4) is removed.

// ------------------------------------------------------------------------------

// Example 2:

// Input:
// head = [1]
// n = 1

// Output:
// []

// Explanation:
// The list has only one node. Removing it results in an empty list.

// ------------------------------------------------------------------------------

// Example 3:

// Input:
// head = [1, 2]
// n = 1

// Output:
// [1]

// Explanation:
// The last node (value 2) is removed.

// ------------------------------------------------------------------------------

// Example 4:

// Input:
// head = [1, 2]
// n = 2

// Output:
// [2]

// Explanation:
// The 2nd node from the end is the head itself, which is removed.

// ------------------------------------------------------------------------------

// Example 5:

// Input:
// head = [10, 20, 30, 40, 50]
// n = 5

// Output:
// [20, 30, 40, 50]

// Explanation:
// The 5th node from the end is the head node (value 10).

// ------------------------------------------------------------------------------

// Note:
// - Your solution must use constant memory (no array or recursion) and complete the removal in a single traversal.
// - You are allowed to modify the linked list.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || !head->next) return NULL;
        ListNode *p = head; 
        ListNode *slow = head; 
        ListNode *fast = head;
        while(fast!= NULL && fast->next!= NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) break;
        }

        if(slow!= fast) return NULL;

        while(p != slow){
            slow = slow->next;
            p = p->next;
        }   

        return p;

    }
};
