class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0;

        // Step 1: Count frequency of each number
        for (int x : nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }

        // Step 2: Count how many elements appear with max frequency
        int count = 0;
        for (auto& p : freq) {
            if (p.second == maxFreq) {
                count += p.second; // add all occurrences
            }
        }

        return count;
    }
};
