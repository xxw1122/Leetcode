class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        seq = [[0 for col in range(n)] for row in range(m)]
        for i in range(n):
            seq[0][i] = 1
        for i in range(m):
            seq[i][0] = 1
        for i in range(1, m):
            for j in range(1, n):
                seq[i][j] = seq[i-1][j] + seq[i][j-1]
        return seq[m-1][n-1]
