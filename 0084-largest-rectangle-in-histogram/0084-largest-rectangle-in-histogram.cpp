class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        if(n == 1) return heights[0];
        int maxarea = 0, temp, l=INT_MAX,b=0;
       for(int i= 0 ; i<= n ; i++){
        int  h = i == n ? 0 : heights[i];
        while(!st.empty() && h  < heights[st.top()]){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : (i - st.top() - 1);

            maxarea = max(height*width , maxarea);
        }
        st.push(i);
       }
        return maxarea;       
        
    }
};