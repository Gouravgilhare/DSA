// Title: Linked List Cycle II

// Difficulty: Medium

// Problem:
// Given the head of a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can 
// be reached again by continuously following the next pointer.

// You must solve the problem without modifying the linked list.

// Constraints:
// - The number of the nodes in the list is in the range [0, 10^4].
// - -10^5 <= Node.val <= 10^5
// - There is at most one cycle in the linked list.

// ------------------------------------------------------------------------------

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Explanation: The tail of the linked list connects to node at index 1 (0-based), value = 2.

// Output: Node with value 2

// ------------------------------------------------------------------------------

// Example 2:

// Input: head = [1,2], pos = 0
// Explanation: The tail connects to the head node (index 0), value = 1.

// Output: Node with value 1

// ------------------------------------------------------------------------------

// Example 3:

// Input: head = [1], pos = -1
// Explanation: The linked list has only one node and no cycle.

// Output: null

// ------------------------------------------------------------------------------

// Example 4:

// Input: head = [], pos = -1
// Explanation: The linked list is empty.

// Output: null

// ------------------------------------------------------------------------------

// Notes:
// - The value `pos` indicates the index (0-based) of the node that the tail connects to.
// - If `pos == -1`, there is no cycle.
// - You should not modify the linked list structure while solving this problem.



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
