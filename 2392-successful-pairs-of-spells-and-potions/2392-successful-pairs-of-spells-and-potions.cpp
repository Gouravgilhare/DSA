
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Step 1: Sort potions for binary search
        sort(potions.begin(), potions.end());
        int m = potions.size();

        vector<int> ans;

        // Step 2: For each spell, find how many potions make the product >= success
        for (int spell : spells) {
            // Minimum potion strength required for this spell
            long long minPotion = (success + spell - 1) / spell;  // ceil(success / spell)

            // Step 3: Find the first potion >= minPotion using binary search
            int idx = lower_bound(potions.begin(), potions.end(), minPotion) - potions.begin();

            // Step 4: All potions from idx to end are successful
            ans.push_back(m - idx);
        }

        return ans;
    }
};