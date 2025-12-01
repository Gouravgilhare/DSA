class Solution {
public:
    vector<string> ans;

    bool isSafe(vector<vector<int>>& maze, int r, int c, vector<vector<int>>& vis) {
        int n = maze.size();
        return (r >= 0 && r < n && c >= 0 && c < n &&
                maze[r][c] == 1 && vis[r][c] == 0);
    }

    void solve(vector<vector<int>>& maze, int r, int c,
               vector<vector<int>>& vis, string path) {

        int n = maze.size();

        // Reached destination
        if (r == n - 1 && c == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[r][c] = 1;

        // Down
        if (isSafe(maze, r + 1, c, vis))
            solve(maze, r + 1, c, vis, path + 'D');

        // Left
        if (isSafe(maze, r, c - 1, vis))
            solve(maze, r, c - 1, vis, path + 'L');

        // Right
        if (isSafe(maze, r, c + 1, vis))
            solve(maze, r, c + 1, vis, path + 'R');

        // Up
        if (isSafe(maze, r - 1, c, vis))
            solve(maze, r - 1, c, vis, path + 'U');

        vis[r][c] = 0; // backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 0) return {}; // no path possible

        solve(maze, 0, 0, vis, "");

        return ans;
    }
};
