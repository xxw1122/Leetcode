#!/usr/bin/env python

class Solution:
    # @return a list of integers
    def grayCode(self, n):
        seq = []
        for i in range(2**n):
            seq.append((i>>1) ^ i)
        return seq