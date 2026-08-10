class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        st.insert(wordList.begin(), wordList.end());
        st.erase(beginWord);
        queue<pair<string, int>>q;

        q.push({beginWord,1});

        while(!q.empty()){
            string node = q.front().first;
            int steps = q.front().second;

            q.pop();

            if(node == endWord) return steps;
        
            for(int i = 0; i< node.size(); i++){
                char orig = node[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    node[i] = ch;

                    if(st.find(node) != st.end()){
                        st.erase(node);
                        q.push({node, steps+1});
                    }
                }
                node[i]= orig;
            }

        }

        return 0;
    }
};