class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for (int i = 0; i < len; i ++) {
            dp[i][i] = true;
        }
        int maxlen = 1, left = 0;
        for (int i = 2; i <= len; i ++) {
            for (int j = 0; j + i - 1 < len; j ++) {
                int k = j + i - 1;
                if (s[j] == s[k] && ((j + 1 >= k - 1) || dp[j + 1][k - 1])) {
                    dp[j][k] = true;
                    if (i > maxlen) {
                        maxlen = i, left = j;
                    }
                }
            }
        }
        return s.substr(left, maxlen);
    }
};