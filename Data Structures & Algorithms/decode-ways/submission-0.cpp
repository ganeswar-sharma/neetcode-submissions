class Solution {
public:

    int solve(int i, string &s, int n, vector<int> &dp){
        if(i >= n){
            return dp[i] = 1;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        if(s[i] == '0'){
            return dp[i] = 0;
        }

        int only_one_char = solve(i + 1, s, n, dp);
        int tow_chars  = 0;
        if(i+1 < n){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                tow_chars = solve(i + 2, s, n, dp);
            }
        }
        return dp[i] = only_one_char + tow_chars;
    }


    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, n, dp);
    }
};
