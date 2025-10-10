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
    ListNode* middleNode(ListNode* head) {
       int cnt= 0;
       ListNode* temp = head;
       ListNode* start = head;

       while(temp != nullptr){
        cnt++;
        temp =temp->next;
       } 
        temp = start;
        int cnt2= 0;
        while(temp != nullptr){
            cnt2++;
            if((cnt/2 +1 )== cnt2){
                return temp;
            }

            temp = temp->next;
        }

        return head;
    }
};