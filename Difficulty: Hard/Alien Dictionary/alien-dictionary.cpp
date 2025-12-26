#define vi vector<int>
#define vvi vector<vector<int>>

class Solution {
  private:
    vi topoSort(int V, vvi&adj, vi&indegree){
        queue<int>q;
        for(int i=0; i< V; i++){
            if(indegree[i]==0)
                q.push(i);
        }
        vi topo;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            topo.push_back(node);
            for(auto a: adj[node])
            {
                indegree[a]--;
                if(indegree[a]==0)
                    q.push(a);
            }
        }
        
        
        return topo;
        
    }
    
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<char>st;
        for(auto &w : words){
            for(char c : w){
                st.insert(c);
            }
        }
        
        
        int N=26;
        int K = st.size();
        vvi adj(N);
        vi indegree(N);
        for(int i=0; i<words.size()-1;i++){
            string a =words[i];
            string b =words[i+1];
            int len = min(a.size(), b.size());
            bool found = false;
            for(int k= 0 ; k<len;k++){
                if(a[k]!=b[k]){
                    adj[a[k]-'a'].push_back(b[k]-'a');
                    indegree[b[k]-'a']++;
                    found=true;
                    break;
                }
            }
            if(!found && a.size() > b.size()) return "";
            
        }       
        
        
        vector<int> topo = topoSort(N,adj,indegree);
        if(topo.size() < N) return "";
        string ans ="";
        for(auto x : topo){
            char c = x+'a';
            if(st.count(c)){
                ans += c;
            }
            
            // ans += char( c+'a');
        }
        
        
        
        return ans;
        
    }
};