
class LRUCache {
public:
class Node{
    public:
    int val , key;
    Node* next, *prev;

    Node(int key , int val){
        this->key = key;
        this->val = val;

        this->next = nullptr;
        this->prev = nullptr;
    }
};
    Node *head ;
    Node *tail ;
    
    unordered_map<int,Node*>mp;
    int cap= 0;
    LRUCache(int capacity) {
        cap = capacity;
        head= new Node(-1,-1);
        tail= new Node(-1,-1);
        head->next= tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        Node*ansNode = mp[key];
        int val = ansNode->val;
        deleteNode(ansNode);
        
        // mp.erase(key);
        addNode(ansNode);

        return val;
    }
    void addNode(Node* newNode){
        newNode->prev = head;
        head->next->prev = newNode;
        newNode->next = head->next;
        head->next = newNode;
    }
    void deleteNode(Node* oldNode){

        oldNode->prev->next = oldNode->next;
        oldNode->next->prev = oldNode->prev;
        oldNode->next= nullptr;
        oldNode->prev= nullptr;
        // delete(oldNode);

    }

    
    
    void put(int key, int value) {
        if(mp.find(key)!= mp.end()){
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
            delete oldNode;
        }

        if(mp.size() == cap){
            Node* node = tail->prev;
            mp.erase(node->key);
            // mp.erase(node->key);
            deleteNode(node);
            delete node;
        }


        Node* newNode  = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */