class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n = arr.size();
        int start = 0, end = 0, sum = 0;
        int minLen = n + 1;

        while (end < n) {
            
            // Expand window
            while (sum <= x && end < n) {
                sum += arr[end++];
            }

            // Shrink window
            while (sum > x && start < end) {
                minLen = min(minLen, end - start);
                sum -= arr[start++];
            }
        }

        return (minLen == n + 1) ? 0 : minLen;
    }
};