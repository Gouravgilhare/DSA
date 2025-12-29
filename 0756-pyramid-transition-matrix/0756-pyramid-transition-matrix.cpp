class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {

        // T[a][b] = bitmask of possible characters above a,b
        vector<vector<int>> T(7, vector<int>(7, 0));

        // Build transition table
        for (auto &s : allowed) {
            int a = s[0] - 'A';
            int b = s[1] - 'A';
            int c = s[2] - 'A';
            T[a][b] |= (1 << c);
        }

        return dfs(bottom, T);
    }

    bool dfs(string curr, vector<vector<int>>& T) {
        if (curr.size() == 1)
            return true;

        vector<int> masks;
        for (int i = 0; i < curr.size() - 1; i++) {
            int a = curr[i] - 'A';
            int b = curr[i + 1] - 'A';
            if (T[a][b] == 0) return false;
            masks.push_back(T[a][b]);
        }

        return buildNext(curr, 0, "", masks, T);
    }

    bool buildNext(string &curr, int idx, string next,
                   vector<int>& masks, vector<vector<int>>& T) {

        if (idx == masks.size())
            return dfs(next, T);

        for (int i = 0; i < 7; i++) {
            if (masks[idx] & (1 << i)) {
                if (buildNext(curr, idx + 1, next + char('A' + i), masks, T))
                    return true;
            }
        }
        return false;
    }
};
