class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.empty() || s.empty()) return 0;
        int lens = s.size(), lent = t.size();
        vector<vector<int> > dp(lens + 1, vector<int>(lent + 1, 0));
        for (int i = 0; i <= lens; i ++) {
            for (int j = 0; j <= lent; j ++) {
                if (i < j) dp[i][j] = 0;
                else if (i == 0 || j == 0) dp[i][j] = 1;
                else if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[lens][lent];
    }
};