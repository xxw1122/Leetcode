#!/usr/bin/env python

def searchMatrix(self, matrix, target):
    m = len(matrix)
    n = len(matrix[0])
    left = 0
    right = m * n - 1
    while left <= right:
        mid = (left + right) / 2
        x = mid / n
        y = mid % n
        if matrix[x][y] == target:
            return True
        elif matrix[x][y] > target:
            right = mid - 1
        elif matrix[x][y] < target:
            left = mid + 1
    return False

