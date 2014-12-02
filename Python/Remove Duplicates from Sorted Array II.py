#!/usr/bin/env python

def removeDuplicates(self, A):
    if len(A) == 0:
        return 0
    pos = 1
    cnt = A[0]
    num = 1
    for i in range(1, len(A)):
        if A[i] == cnt:
            num += 1
        else:
            num = 1
            cnt = A[i]
        if num <= 2:
            A[pos] = cnt
            pos += 1