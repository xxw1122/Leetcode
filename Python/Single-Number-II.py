#!/usr/bin/env python

def singleNumber(self, A):
        bit = [0 for i in xrange(32)]
        for x in A:
            for i in xrange(32):
                if x & (1 << i) == 1 << i: bit[i] += 1
        res = 0
        if bit[31] % 3 == 0: # posivie
            for i in xrange(31):
                if bit[i] % 3 == 1: res += 1 << i
        else: # negative
            for i in xrange(31):
                if bit[i] % 3 == 0: res += 1 << i
            res = -(res + 1)
        return res