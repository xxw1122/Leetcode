#!/usr/bin/env python

def uniquePathsWithObstacles(self, obstacleGrid):
    m = len(obstacleGrid)
    if m == 0:
        return 0
    n = len(obstacleGrid[0])
    if obstacleGrid[0][0] == 1:
        return 0
    seq = [[0 for col in range(n)] for row in range(m)]
    seq[0][0] = 1
    for i in range(1, n):
        if obstacleGrid[0][i] == 1:
            seq[0][i] = 0
        else:
            seq[0][i] = seq[0][i-1]
    for i in range(1, m):
        if obstacleGrid[i][0] == 1:
            seq[i][0] = 0
        else:
            seq[i][0] = seq[i-1][0]
    for i in range(1, m):
        for j in range(1, n):
            if obstacleGrid[i][j] == 1:
                seq[i][j] = 0
            else:
                seq[i][j] = seq[i-1][j] + seq[i][j-1]
    return seq[m-1][n-1]