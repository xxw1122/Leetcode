#!/usr/bin/env python

class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
        left = 0
        right = x
        while left <= right:
            mid = (left + right) / 2
            if mid * mid <= x and (mid + 1) * (mid + 1) > x:
                return mid
            elif mid * mid > x:
                right = mid - 1
            else:
                left = mid + 1