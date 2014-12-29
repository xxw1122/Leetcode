class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        d = {}
        for i in range(26):
            d[chr(i+65)] = i + 1
        res = 0
        for i in range(len(s)):
            res = res * 26 + d[s[i]]
        return res