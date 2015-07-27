class Solution:
    # @return an integer
    def numDistinct(self, S, T):
        len1 = len(S)
        len2 = len(T)
        seq = [[0 for col in range(len2+1)] for row in range(len1+1)]
        for i in range(len1+1):
            for j in range(len2+1):
                if i < j:
                    seq [i][j] = 0
                elif i == 0 or j == 0:
                    seq[i][j] = 1
                else:
                    if S[i-1] != T[j-1]:
                        seq[i][j] = seq[i-1][j];
                    else:
                        seq[i][j] = seq[i-1][j] + seq[i-1][j-1]
        return seq[len1][len2]