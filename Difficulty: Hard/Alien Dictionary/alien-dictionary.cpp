class Solution {
  public:
  
    bool isCycle(int src , vector<bool>&vis, vector<bool>&pathRec, vector<vector<int>>&adjs ){
        vis[src]=true;
        pathRec[src] = true;
        
        for (int v : adjs[src]) {
            if (!vis[v]) {
                if (isCycle(v, vis, pathRec, adjs))
                    return true;
            }
            else if (pathRec[v]) {
                return true;
            }
        }
        
        pathRec[src]=false;
        return false;
    }
    
    //toposort
        
    void topoSort(int src , vector<bool>&vis, stack<int>&st, vector<vector<int>>&adjs){
        vis[src]= true;
        
       for (int v : adjs[src]) {
            if (!vis[v]) {
                topoSort(v, vis, st, adjs);
            }
        }
        st.push(src);
        
    }
        
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<vector<int>>adjs(26);
        vector<bool>present(26,false);
        
        for(auto word : words){
            for(auto c : word){
                present[c-'a']=true;
            }
        }
        
        for(int i = 0; i< n-1; i++){

            string s1 = words[i];
            string s2 = words[i+1];
        
            int minSize = min(s1.size(), s2.size());
            if (s1.size() > s2.size() && s1.substr(0, minSize) == s2)
                return "";
                
            for (int j = 0; j < minSize; j++) {
                if (s1[j] != s2[j]) {
                    adjs[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
            
        }
        
        vector<bool>vis(26, false);
        vector<bool>pathRec(26,false);
        
        //checking cyclic dependency
        for(int i = 0 ; i< 26; i++){
           if ( present[i] && !vis[i]) {
                if (isCycle(i, vis, pathRec, adjs))
                    return "";
            }
        }
        
        stack<int>st;
        vis.assign(26, false);
        for(int i = 0 ; i< 26; i++){
            if(present[i] && !vis[i]){
                topoSort(i, vis, st,adjs);
            }
        }
        
        string ans="";
        while(!st.empty()){
            int  c = st.top();
            st.pop();
            
            ans += (char)(c + 'a');
        }
        
        return ans;
    }
};