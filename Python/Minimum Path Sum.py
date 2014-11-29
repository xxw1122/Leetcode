#!/usr/bin/env python

def minPathSum(self, grid):
    m = len(grid)
    n = len(grid[0])
    seq = [[0 for col in range(n)] for row in range(m)]
    seq[0][0] = grid[0][0]
    for i in range(1,n):
        seq[0][i] = grid[0][i] + seq[0][i-1]
    for i in range(1,m):
        seq[i][0] = grid[i][0] + seq[i-1][0]
    for i in range(1,m):
        for j in range(1,n):
            seq[i][j] = min(seq[i-1][j],seq[i][j-1]) + grid[i][j]
    return seq[m-1][n-1]