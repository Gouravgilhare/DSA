class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n, -1);     // default -1 if no greater element
        stack<int> st;             // store values (next greater candidates)

        // We iterate from 2*n-1 down to 0 and use idx = i % n
        // For i >= n we only build the stack (simulate the wrap),
        // for i < n we both query and then push.
        for (int i = 2*n - 1; i >= 0; --i) {
            int idx = i % n;
            // Pop smaller-or-equal elements: we want strictly greater
            while (!st.empty() && st.top() <= arr[idx]) st.pop();

            if (i < n) {
                if (!st.empty()) nge[idx] = st.top();
                // else nge[idx] stays -1
            }

            st.push(arr[idx]);
        }

        return nge;
    }
};
