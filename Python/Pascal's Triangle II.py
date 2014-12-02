#!/usr/bin/env python

def getRow(self, rowIndex):
    seq = [1]
    if rowIndex == 0:
        return seq
    for i in range(rowIndex+1):
        cnt = []
        for j in range(i+1):
            if j == 0:
                cnt.append(seq[j])
            elif j == i:
                cnt.append(seq[j-1])
            else:
                cnt.append(seq[j] + seq[j-1])
        seq = cnt
    return seq