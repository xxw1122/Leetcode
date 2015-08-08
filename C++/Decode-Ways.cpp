class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        if (len == 0) return 0;
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= len; i ++) {
            if (s[i - 1] == '0') {
                if (i >= 2 && s[i - 2] < '3' && s[i - 2] != '0') {
                    dp[i] += dp[i - 2];
                }
            } else {
                dp[i] += dp[i - 1];
                if (i >= 2 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + s[i - 1] - '0') <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[len];
    }
};