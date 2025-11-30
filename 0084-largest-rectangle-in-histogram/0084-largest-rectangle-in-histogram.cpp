class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        
        vector<int>right(n);
        stack<int>st;
        for(int i= n-1 ;i>=0; i-- ){

            while(!st.empty() && ht[st.top()] >= ht[i]  )
                st.pop();

            if(st.empty())right[i]=n;
            else  right[i]=st.top();

            st.push(i);
        }


        while(!st.empty()) st.pop();

        vector<int>left(n);
        // vector<int>st;
        for(int i= 0 ;i<n; i++ ){

            while(!st.empty() && ht[st.top()] >= ht[i]  )
                st.pop();

            if(st.empty())left[i]=-1;
            else  left[i]=st.top();

            st.push(i);
        }


    int maxArea =INT_MIN;

        for(int i = 0 ; i< n ; i++){
            int area = 0;

            int width= right[i] -left[i]  -1;

            area = width * ht[i];

            maxArea = max(area, maxArea);


        }



        return maxArea;


    }
};