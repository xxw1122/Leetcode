class Solution:
    # @param s, a string
    # @return an integer
    def minCut(self, s):
        len1 = len(s)
        seq = [[0 for col in range(len1 + 1)] for row in range(len1 + 1)]
        for i in range(len1+1):
            seq[i][i] = 1
        for i in range(2, len1+1):
            for j in range(len1+1-i):
                r = j + i - 1
                if s[j] == s[r]:
                    if j + 1 >= r - 1 or seq[j+1][r-1] == 1:
                        seq[j][r] = 1
        res = [len1] * len1
        res[0] = 0
        for i in range(1, len1):
            if seq[0][i] == 1:
                res[i] = 0
                continue
            for j in range(1,i+1):
                if seq[j][i] == 1:
                    res[i] = min(res[i], res[j-1]+1)
        return res[len1-1]