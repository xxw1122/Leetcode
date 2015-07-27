#!/usr/bin/env python

def setZeroes(self, matrix):
    tagx = 1
    tagy = 1
    m = len(matrix)
    n = len(matrix[0])
    for i in range(m):
        if matrix[i][0] == 0:
            tagy = 0
    for i in range(n):
        if matrix[0][i] == 0:
            tagx = 0
    for i in range(1, m):
        for j in range(1, n):
            if matrix[i][j] == 0:
                matrix[i][0] = 0
                matrix[0][j] = 0
    for i in range(1, n):
        if matrix[0][i] == 0:
            for j in range(m):
                matrix[j][i] = 0
    for i in range(1, m):
        if matrix[i][0] == 0:
            for j in range(n):
                matrix[i][j] = 0
    if tagx == 0:
        for i in range(n):
            matrix[0][i] = 0
    if tagy == 0:
        for i in range(m):
            matrix[i][0] = 0