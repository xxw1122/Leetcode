class Solution:
    # @return a string
    def longestPalindrome(self, s):
        len1 = len(s)
        seq = [[0 for col in range(len1 + 1)] for row in range(len1 + 1)]
        for i in range(len1+1):
            seq[i][i] = 1
        maxsub = 1
        left = 0
        right = 0
        for i in range(2, len1+1):
            for j in range(len1+1-i):
                r = j + i - 1
                if s[j] == s[r]:
                    if j + 1 >= r - 1 or seq[j+1][r-1] == 1:
                        seq[j][r] = 1
                        if r - j + 1 > maxsub:
                            maxsub = r - j + 1
                            left = j
                            right = r
        return s[left:right+1]