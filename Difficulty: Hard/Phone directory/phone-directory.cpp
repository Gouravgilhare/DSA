// User function Template for C++

class Node{
    
public:
    Node* links[26];
    bool flag;
    
    Node(){
        flag= false;
        for(int i = 0 ; i< 26; i++){
            links[i]=nullptr;
        }
    }
    
    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    
    Node* get(char ch){
        return links[ch-'a'];
        
    }
    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    bool getEnd(){
        return flag; 
    }
};

class Trie{
    private : Node *root;
    public:
        Trie(){
            root = new Node();
        }
        
        void dfs(Node* node, string prefix, vector<string>&result){
            if(node->getEnd()) result.push_back(prefix);
            
            for(int i= 0 ; i< 26; i++){
                if(node->links[i]!=nullptr){
                    char ch = 'a'+i;
                    dfs(node->links[i], prefix+ch, result);
                }
            }
            
        }
        
        void insert(string &word){
            Node * node = root;
               for(char w : word){
                if(!node->containsKey(w)){
                    node->put(w, new Node());
                }
                node = node->get(w);
            }
            node->setEnd();
        }
        
        vector<string> getSuggestions(string prefix){
            Node* node = root;
            for(char ch : prefix){
                if(!node->containsKey(ch)){
                    return {"0"};
                }else
                    node = node->get(ch);
            }
            
            vector<string>result;
            dfs(node,prefix, result);
            
            return result;
        }

};

class Solution {
  public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        // code here
        Trie trie;
        
        if(s.size()==0 || n==0) return {{0}};
        
        
        for(int i = 0 ; i< n ; i++){
            trie.insert(contact[i]);
        }
        
        
        vector<string>searchResult;
        vector<vector<string>>ans;
        
        string pre = ""; 
        for(char ch : s){
            pre += ch;
            ans.push_back(trie.getSuggestions(pre));
        }
        
        
        return ans;
        
        
    }
};