struct Node {
    Node *links[26];
    bool flag = false;

    Node(){
        flag =false;
        for(int i = 0; i < 26 ; i++)
            links[i]= nullptr;
    }

    bool containsKey(char ch){
        return (links[ch-'a']!=nullptr);
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch, Node* node){
        links[ch-'a']=node;
    }

    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }

    int countChildren(){

        int count = 0;
        for(int i= 0; i< 26; i++){
            if(links[i]!= nullptr)count++;
        }
        return count;
    }
};

class Trie{
    private:
     Node *root;
    public:
        Trie(){
            root= new Node();
        }
        void insert(string word){
            Node *node  = root;
            for(auto w : word){
                if(!node->containsKey(w))
                    node->put(w, new Node());
                node = node->get(w);
            }
            node->setEnd();
        }
        bool  search( string word){
            Node* node = root;
            for(auto w : word){
                if(!node->containsKey(w)){
                    return false;
                }
                    node= node->get(w);
            }

            return node->getEnd();
        }

        Node* getRoot(){
            return root;
        }

        string lcp(){
            string prefix = "";
            Node* node = root;

            while(node){
                if(node->countChildren()==1 && !node->getEnd() ){
                    for(int i =0 ; i<26; i++){
                        if(node->links[i]!= nullptr){
                            prefix += char(i+'a');
                            node= node->links[i];
                            break;
                        }
                    }
                }

                else break;
            }

            return prefix;
        }
};

class Solution {

// private:
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        if(s.empty()) return "";
        // sort(s.begin(),s.end());

        Trie  trie;
        string first = s[0];
        string last = s[n-1];

        string ans = "";

        for(auto w : s){
            trie.insert(w);
        }


        return trie.lcp();
    }
};