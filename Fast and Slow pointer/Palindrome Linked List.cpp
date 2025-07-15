// Title: Palindrome Linked List

// Difficulty: Easy / Medium

// Problem:
// Given the head of a singly linked list, return true if the linked list is a palindrome.

// A palindrome is a sequence that reads the same backward as forward.

// You must solve it in O(n) time and O(1) space.

// ---

// Function Signature (C++):
// bool isPalindrome(ListNode* head);

// ---

// Constraints:
// - The number of nodes in the list is in the range [1, 10⁵].
// - 0 <= Node.val <= 9

// ---

// Example 1:

// Input:
// head = [1, 2, 2, 1]

// Output:
// true

// Explanation:
// The list reads the same forward and backward.

// ---

// Example 2:

// Input:
// head = [1, 2]

// Output:
// false

// Explanation:
// The list is not a palindrome.

// ---

// Example 3:

// Input:
// head = [1]

// Output:
// true

// Explanation:
// A single element list is always a palindrome.

// ---

// Example 4:

// Input:
// head = [1, 0, 1]

// Output:
// true

// ---

// Example 5:

// Input:
// head = [1, 2, 3, 2, 1]

// Output:
// true

// ---

// Example 6:

// Input:
// head = [1, 2, 3, 4, 5]

// Output:
// false

// ---

// Note:
// - You may **reverse the second half of the list** to compare both halves in-place.
// - Do not use extra space like arrays, stacks, or recursion.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast && fast->next){
            fast= fast->next->next;
            slow = slow->next;
        }

        ListNode *prev = nullptr;
        while(slow){
            ListNode* temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        } 

        while(prev){
            if(head->val != prev->val ) return false;
            head= head->next;
            prev = prev->next;
        }


        return true;
    }
};
