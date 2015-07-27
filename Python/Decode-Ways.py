class Solution:
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
        length = len(s)
        if length == 0:
            return 0
        dp = [0] * (length + 1)
        dp[0] = 1
        if s[0] != '0':
            dp[1] = 1
        for i in range(2, length+1):
            cnt = int(s[i-2]) * 10 + int(s[i-1])
            if s[i-1] == '0' and cnt <= 26 and cnt > 0:
                dp[i] = dp[i-2]
            elif s[i-1] != '0' and s[i-2] != '0' and cnt <= 26 and cnt > 0:
                dp[i] = dp[i-2] + dp[i-1]
            elif s[i-1] != '0':
                dp[i] = dp[i-1]
        return dp[length]