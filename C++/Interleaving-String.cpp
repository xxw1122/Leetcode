class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 + len2 != s3.size()) return false;
        vector<vector<bool> > dp(len1 + 1, vector<bool>(len2 + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0 && dp[0][j - 1] && s2[j - 1] == s3[j - 1]) {
                    dp[i][j] = true;
                } else if (j == 0 && dp[i - 1][0] && s1[i - 1] == s3[i - 1]) {
                    dp[i][j] = true;
                } else if (i > 0 && s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) {
                    dp[i][j] = true;
                } else if (j > 0 && s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
        return dp[len1][len2];
    }
};