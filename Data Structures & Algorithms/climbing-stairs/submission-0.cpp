class Solution {
public:

    int func(int i, int n, vector<int> &dp){
        if(i == n){
            return dp[n];
        }
        if(i > n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = func(i + 1, n, dp) + func(i + 2, n, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[n] = 1;
        func(0, n, dp);
        return dp[0];
    }
};
