class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int>st;
        int n = mat.size();
        for(int i = 0 ; i<n ; i++ ){
            st.push(i);
        }
        
        while(st.size() > 1)
        {
            int i = st.top();
                st.pop();
            int j = st.top();
                st.pop();
            
            if(mat[i][j]== 0){
                st.push(i);
            }else
                st.push(j);
        }
        
        
        int cele = st.top();
        
        for(int i = 0; i< n ; i++){
            if( (i!= cele) && (mat[i][cele]==0 || mat[cele][i]==1))
                return -1;
        }   
        return cele;
    }
};