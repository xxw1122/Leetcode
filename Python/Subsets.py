#!/usr/bin/env python

import copy

class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def generate(self, seq, S, s, num):
        if num == len(S):
            seq.append(copy.copy(s))
            return seq
        seq = self.generate(seq, S, s, num+1)
        s.append(S[num])
        seq = self.generate(seq, S, s, num+1)
        s.pop()
        return seq
    def subsets(self, S):
        seq = []
        s = []
        S.sort()
        return self.generate(seq, S, s, 0)