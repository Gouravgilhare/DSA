class Solution {
public:
    bool isSafe(vector<vector<int>>& maze, int i, int j, vector<vector<int>>& vis) {
        int n = maze.size();
        return (i >= 0 && j >= 0 && i < n && j < n && maze[i][j] == 1 && vis[i][j] == 0);
    }

    void Maze(int n, vector<string>& ans, vector<vector<int>>& vis, string path,
              vector<vector<int>>& maze, int i, int j) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        vis[i][j] = 1;

        // ↓ Down
        if (isSafe(maze, i + 1, j, vis))
            Maze(n, ans, vis, path + 'D', maze, i + 1, j);

        // ← Left
        if (isSafe(maze, i, j - 1, vis))
            Maze(n, ans, vis, path + 'L', maze, i, j - 1);

        // → Right
        if (isSafe(maze, i, j + 1, vis))
            Maze(n, ans, vis, path + 'R', maze, i, j + 1);

        // ↑ Up
        if (isSafe(maze, i - 1, j, vis))
            Maze(n, ans, vis, path + 'U', maze, i - 1, j);

        vis[i][j] = 0; // backtrack
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 0) return ans;

        Maze(n, ans, vis, "", maze, 0, 0);
        return ans;
    }
};
