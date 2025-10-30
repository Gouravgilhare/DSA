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
    ListNode* reverse(ListNode* head, int k){
        if(!head) return nullptr;
        ListNode* temp = head;
        int cnt = 0;
        while(cnt < k){
            if(temp== nullptr)return head;
            temp =temp->next;
            cnt++;
        }

        ListNode* prev = nullptr;
        temp = head;cnt=0;
        ListNode* next=nullptr, *curr=head;
        while(cnt<k && curr!= nullptr){
            next =curr->next;
            curr->next= prev;
            prev=curr;
            curr = next;
            cnt++;
        }
        head->next =  reverse(curr, k);

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        return reverse(head,k);
    }
};