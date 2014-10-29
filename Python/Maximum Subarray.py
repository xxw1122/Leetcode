#!/usr/bin/env python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxSubArray(self, A):
        maxsum = A[0]
        s = A[0]
        for i in range(1, len(A)):
            if s < 0:
                s = 0
            s += A[i]
            maxsum = max(maxsum, s)
        return maxsum