#!/usr/bin/env python

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
        dp = [0, 1]
        for i in range(2, 20):
            dp.append(dp[i-1] + dp[i-2])
        return dp[n]