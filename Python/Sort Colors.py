#!/usr/bin/env python

def sortColors(self, A):
    vis = [0] * 3
    for i in range(len(A)):
        vis[A[i]] += 1
    pos = 0
    num = 0
    while num < vis[0]:
        A[pos] = 0
        pos += 1
        num += 1
    num = 0
    while num < vis[1]:
        A[pos] = 1
        pos += 1
        num += 1
    num = 0
    while num < vis[2]:
        A[pos] = 2
        pos += 1
        num += 1
    return A