class Solution {
public:
    int func(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int robHouse = nums[i] + func(i+2, n, nums, dp);
        int noRob = func(i+1, n,nums, dp);
        return dp[i] = max(robHouse, noRob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        return max(func(0, n-1, nums, dp1), func(1, n, nums, dp2));
    }
};
