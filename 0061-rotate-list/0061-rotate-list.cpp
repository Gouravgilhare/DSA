class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Step 1: find length and last node
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: make it circular
        tail->next = head;

        // Step 3: find the new tail (len - k % len steps)
        k = k % len;
        int stepsToNewHead = len - k;
        ListNode* newTail = tail;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }

        // Step 4: break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
