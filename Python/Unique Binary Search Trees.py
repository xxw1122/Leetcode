class Solution:
    # @return an integer
    def numTrees(self, n):
        dp = []
        dp.append(1);
        for i in range(1, 15):
            res = 0;
            for j in range(1, i+1):
                 res += dp[j-1] * dp[i-j];
            dp.append(res);
        return dp[n];