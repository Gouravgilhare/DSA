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

    Node* flattenDFS(Node*head){
        Node* curr = head;
        Node* last = head;

        while(curr){
            Node * next = curr->next;
            
            if(curr->child){
                Node* child = curr->child;
                Node* tail = flattenDFS(child);
                // child->prev =curr;
                curr->next= child;
                child->prev= curr;
                curr->child= nullptr;


                if(next){
                    tail->next = next;
                    next->prev = tail;
                }

                // if(!curr->next){
                //     curr->next = next;
                //     next->prev= curr;
                // }
                last= tail;
                curr= next;
            }else{
                last= curr;
                curr = next;
            }
            // curr= curr->next;
            

        }

        return last;
    }
    Node* flatten(Node* head) {
        if(!head) return NULL;
        flattenDFS(head);
        
        return head;
    }   
};