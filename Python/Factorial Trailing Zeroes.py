class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        res = 5
        cnt = 0
        while res <= n:
            cnt += n / res
            res *= 5
        return cnt