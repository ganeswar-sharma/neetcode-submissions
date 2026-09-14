class Solution {
public:

    int findPaths(int currRow,int currCol,int m,int n,vector<vector<int>> &dp){
        if(currRow >=m || currCol >=n){
            return 0;
        }
        if(currRow == m-1 && currCol == n-1){
            return 1;
        }
        if(dp[currRow][currCol] != -1){
            return dp[currRow][currCol];
        }
        dp[currRow][currCol] = findPaths(currRow, currCol + 1, m, n, dp) +
        findPaths(currRow + 1, currCol, m, n, dp);
        return dp[currRow][currCol];
    }

    int uniquePaths(int m, int n) {
        int currRow = 0;
        int currCol = 0;
        vector<vector<int>> dp(m,vector<int>(n,-1)); 
        return findPaths(currRow, currCol, m, n, dp);
    }
};
