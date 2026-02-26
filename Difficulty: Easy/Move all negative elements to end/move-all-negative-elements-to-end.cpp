class Solution {
  public:
    void segregateElements(vector<int>& arr) {
        // Your code goes 
        
        int n = arr.size();
                int j = n-1;
        
        stack<int>st1;
        stack<int>st2;
        
        for(int i = n-1 ; i>=0  ; i-- ){
            if(arr[i]>=0) st1.push(arr[i]);   
            else st2.push(arr[i]);
            
        }
        int i= 0;
        while(!st1.empty()){
            arr[i] = st1.top();
            st1.pop();
            i++;
        }
        while(!st2.empty()){
            arr[i] = st2.top();
            st2.pop();
        
            i++;
        }
        
        
    }
};