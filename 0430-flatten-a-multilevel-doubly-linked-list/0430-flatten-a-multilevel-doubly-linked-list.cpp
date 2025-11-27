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
    Node* flattenDFS(Node* head) {
        Node* last = head;
        Node* curr = head;

        while(curr){
            Node *next= curr->next;

            if(curr->child){
                Node* child = curr->child;
                Node* tail = flattenDFS(child);

                curr->next = child;
                child->prev = curr;

                curr->child = nullptr;

                if(next) {
                    tail->next= next;
                    next->prev= tail;
                }


                last= tail;
                curr = next;

            }else{
                last= curr;
                curr= next;
            }
        }

        return last;

    }
    Node* flatten(Node* head) {
        
        if(!head) return nullptr;

       flattenDFS(head);
        return head;

    }
};