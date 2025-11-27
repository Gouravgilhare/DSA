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
        ListNode*temp = head, * start= head, * last;
        int cnt = 0;
        while(temp->next){
            cnt++;
            temp =temp->next;
        }
        last= temp;
        temp = start;
        if(cnt%2== 1){
            cnt/=2;
            cnt++;
        }else{
            cnt/=2;
        }
        while(cnt--){
            temp= temp->next;
        }
        return temp;

    }
};