class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st(deadends.begin(), deadends.end());

        if(st.count("0000"))
            return -1;
            
        queue<pair<string,int>>q;
        q.push({"0000" , 0});
        
        st.insert("0000");
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == target){
                return steps;
            }

            for(int i = 0 ; i < word.size(); i++){
                char orig = word[i];

                int digit = word[i] - '0';

                // +1
                word[i] = '0' + (digit + 1) % 10;

                if(st.find(word) == st.end()){
                    st.insert(word);
                    q.push({word, steps + 1});
                }

                // -1
                word[i] = '0' + (digit + 9) % 10;

                if(st.find(word) == st.end()){
                    st.insert(word);
                    q.push({word, steps + 1});
                }
                word[i] = orig;
            }
        }
        
        return -1;
    }
};