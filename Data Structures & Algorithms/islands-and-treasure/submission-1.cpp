class Solution {
   public:
    bool isValid(int i, int j, int rows, int cols) {
        if (i >= rows || i < 0 || j >= cols || j < 0) {
            return false;
        }
        return true;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            vector<int> x = {-1, 1, 0, 0};
            vector<int> y = {0, 0, -1, 1};
            for (int k = 0; k < 4; k++) {
                int dx = i + x[k];
                int dy = j + y[k];
                if (isValid(dx, dy, rows, cols) && vis[dx][dy] == false &&
                    grid[dx][dy] == INT_MAX) {
                    vis[dx][dy] = true;
                    q.push({{dx, dy}, min(grid[dx][dy], dist + 1)});
                    grid[dx][dy] = min(grid[dx][dy], dist + 1);
                }
            }
        }
    }
};
