#!/usr/bin/env python


def canJump(self, A):
    lenth = len(A) - 1
    if lenth <= 0:
        return True
    maxlenth = A[0]
    for i in range(lenth+1):
        if i <= maxlenth:
            maxlenth = max(maxlenth, A[i] + i)
        else:
            return False
        if maxlenth >= lenth:
            return True