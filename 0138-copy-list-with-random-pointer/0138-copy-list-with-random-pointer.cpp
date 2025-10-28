/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        unordered_map<Node*, Node*>map;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;

        map[head] = newHead;
        while(oldTemp!= nullptr){
            Node* copyNode= new Node(oldTemp->val);
            map[oldTemp] =copyNode; 
            newTemp->next = copyNode;
            oldTemp=oldTemp->next;
            newTemp = newTemp->next;
        }

        oldTemp = head;
        newTemp = newHead;

        while(oldTemp!=nullptr){
            newTemp->random = map[oldTemp->random];
            newTemp = newTemp->next;
            oldTemp = oldTemp->next;
        }

        return newHead;

    }
};