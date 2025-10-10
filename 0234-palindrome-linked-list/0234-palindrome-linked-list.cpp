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
        ListNode *fast =head;
        ListNode *slow=head;

        while(fast!= nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast!= nullptr){
            slow = slow->next;
        }

        slow = reverselist(slow);
        fast= head;

        while(slow != nullptr){
            if(slow->val != fast->val) return false;
            fast= fast->next;
            slow = slow->next;
        }

        return true;
    }


    private:
        ListNode* reverselist(ListNode* head){
            ListNode* curr = head, *next = nullptr, *prev= nullptr, temp;

            while(curr!= nullptr ){
                next = curr->next;
                 curr->next = prev;
                 prev= curr;
                 curr= next;
            }
            return prev;
        }
};