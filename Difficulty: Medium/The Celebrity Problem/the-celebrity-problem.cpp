class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        stack<int>st;
        for(int i = 0 ; i< n ; i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int i = st.top() ; 
            st.pop();
            int j = st.top();
            st.pop();
            
            if(mat[i][j]==0){
                st.push(i);
            }else
                st.push(j);
                
        }
        int cele  = st.top();
        
        for(int i = 0 ; i< n ;i++){
            // for(int j = 0 ; j < n ;j++){
            
            if((i!=cele)&&(mat[cele][i]== 1)|| mat[i][cele] == 0 )return -1;
             
                // if() return -1;
            
        }
        
        return cele;
        
        
    }
};