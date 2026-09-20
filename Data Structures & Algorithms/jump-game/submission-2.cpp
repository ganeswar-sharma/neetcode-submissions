class Solution {
public:

    bool canReach(vector<int>& arr, int i, int n, vector<int> &dp) {
        if (i == n - 1) {
            return true;
        }

        if (dp[i] != -1) {
            return dp[i];
        }
        for (int j = 1; j <= arr[i]; j++) {
            if (canReach(arr, i + j, n, dp)) {
                return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }

    bool canJump(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, -1);


        return canReach(arr, 0, n, dp);
    }
};