#!/usr/bin/env python

def generate(self, numRows):
    triangle = []
    if numRows == 0:
        return triangle
    triangle.append([1])
    for i in range(1, numRows):
        row = []
        for j in range(i+1):
            if j == 0:
                row.append(triangle[i-1][j])
            elif j == i:
                row.append(triangle[i-1][j-1])
            else:
                row.append(triangle[i-1][j-1] + triangle[i-1][j])
        triangle.append(row)
    return triangle