#!/usr/bin/env python

import copy

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def generate(self, candidates, target, seq, cnt, num):
        if target == 0:
            seq.append(copy.copy(cnt))
            return seq
        if num >= len(candidates):
            return seq
        if target >= candidates[num]:
            cnt.append(candidates[num])
            seq = self.generate(candidates, target - candidates[num], seq, cnt, num)
            cnt.pop()
        if num + 1 < len(candidates):
            seq = self.generate(candidates, target, seq, cnt, num+1)
        return seq
    def combinationSum(self, candidates, target):
        seq = []
        cnt = []
        candidates.sort()
        return self.generate(candidates, target, seq, cnt, 0)