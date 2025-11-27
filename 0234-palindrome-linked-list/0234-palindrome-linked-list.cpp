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

    ListNode* reverseList(ListNode* head){
        ListNode* next = head;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        // ListNode* next = head;

        while(curr){
            next= curr->next;
            curr->next= prev;
            prev= curr;
            curr= next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* fast= head;
        ListNode* slow= head;

        while(fast && fast->next){
            fast= fast->next->next;
            slow= slow->next;
        }
        slow=reverseList(slow);
        
        ListNode *first = head;
        ListNode*second = slow;
        while(second){
            if(first->val != second->val){
                return false;
            }
            first=first->next;
            second= second->next;
        }

        return true;
    }
};