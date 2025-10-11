/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        flattenDFS(head);
        return head;
    }

private:
    Node* flattenDFS(Node* head) {
        Node* curr = head;
        Node* last = nullptr;

        while (curr) {
            Node* next = curr->next;

            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenDFS(childHead); // recursively flatten child

                // Connect current node with child head
                curr->next = childHead;
                childHead->prev = curr;

                // Connect child's tail to the next node
                if (next) {
                    childTail->next = next;
                    next->prev = childTail;
                }

                curr->child = nullptr; // clear the child pointer
                last = childTail;
                curr = next;
            } else {
                last = curr;
                curr = curr->next;
            }
        }

        return last;
    }
};
