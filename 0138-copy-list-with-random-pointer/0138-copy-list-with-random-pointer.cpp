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
        Node* temp = head;
        unordered_map<Node*, Node*>mp;
       
        int cnt = 0;
        while(temp!= NULL){
            mp[temp] = new Node(temp->val);
            temp =temp->next;
        }   


        temp = head;
        // temp2= newList;
        int c = 0;
        while(temp){
            
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];

            
            // temp2= temp2->next;
            temp=temp->next;
        }


        return mp[head];

    }
};