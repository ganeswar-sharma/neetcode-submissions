class Solution {
public:

    int func(int i, int n, vector<int> &cost, vector<int> &dp){
        if(i == n){
            return dp[n];
        }
        if(i > n){
            return 1e9;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        // take one step and take 2 steps 
        int oneStep = cost[i] + func(i+1,n,cost, dp);
        int twoSteps = cost[i] + func(i + 2,n,cost, dp);
        return dp[i] = min(oneStep, twoSteps);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        dp[n] =0;
        return min(func(0, n, cost, dp), func(1, n, cost, dp));
    }
};
