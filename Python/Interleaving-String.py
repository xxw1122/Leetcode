class Solution:
    # @return a boolean
    def isInterleave(self, s1, s2, s3):
        len1 = len(s1)
        len2 = len(s2)
        if len1 + len2 != len(s3):
            return False
        seq = [[0 for col in range(len2+1)] for row in range(len1+1)]
        seq[0][0] = 1
        for i in range(len1+1):
            for j in range(len2+1):
                if i > 0 and s1[i-1] == s3[i-1+j] and seq[i-1][j] == 1:
                    seq[i][j] = 1
                if j > 0 and s2[j-1] == s3[j-1+i] and seq[i][j-1] == 1:
                    seq[i][j] = 1
        if seq[i][j] == 1:
            return True
        else:
            return False