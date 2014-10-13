#!/usr/bin/env python

class Solution:
    # @return an integer
    def reverse(self, x):
        pos = True
        if x < 0 :
            pos =False
            x=-x
        k=0
        while x != 0 :
            k = k * 10 + x % 10
            x = x / 10
        if not pos:
            return -k
        return k