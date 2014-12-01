#!/usr/bin/env python

def rotate(self, matrix):
    n = len(matrix)
    seq = [[0 for col in range(n)] for row in range(n)]
    for i in range(n):
        for j in range(n):
            seq[j][n-1-i] = matrix[i][j]
    return seq