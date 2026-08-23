class Solution {
public:

    bool isValid(int i , int j , int rows, int cols){
        if(i >= rows || i < 0 || j >= cols || j < 0){
            return false;
        }
        return true;
    }

    void dfs(int i , int j, int rows, int cols, vector<vector<char>>& grid, vector<vector<bool>> &vis){
        vis[i][j] = true;
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        for(int k =0;k<4;k++){
            int dx = i + x[k];
            int dy = j + y[k];
            if(isValid(dx, dy, rows, cols) && vis[dx][dy] == false && grid[i][j] == '1'){
                dfs(dx, dy, rows, cols, grid, vis);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        for(int i =0;i<rows;i++){
            for(int j =0;j<cols;j++){
                if(isValid(i, j , rows, cols) && grid[i][j] == '1' && vis[i][j] == false){
                    dfs(i,j, rows,cols, grid, vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};
