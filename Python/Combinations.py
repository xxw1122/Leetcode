#!/usr/bin/env python

import copy

class Solution:
    # @return a list of lists of integers
    def generate(self, seq, s, n, k, cnt):
        if cnt == n + 1 and len(s) == k:
            seq.append(copy.copy(s))
            return seq
        if cnt == n + 1:
            return seq
        seq = self.generate(seq, s, n, k, cnt+1)
        s.append(cnt)
        seq = self.generate(seq, s, n, k, cnt+1)
        seq.pop()
        return seq
    def combine(self, n, k):
        seq = []
        s = []
        seq = self.generate(seq, s, n, k, 1)
        return seq