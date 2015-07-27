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
    def subsetsWithDup(self, S):
        seq = []
        s = []
        S.sort()
        seq = self.generate(seq, S, s, 0)
        new_seq = []
        for item in seq:
            if item not in new_seq:
                new_seq.append(item)
        return new_seq