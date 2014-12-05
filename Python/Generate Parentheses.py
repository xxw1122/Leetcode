#!/usr/bin/env python


class Solution:
    # @param an integer
    # @return a list of string
    def generate(self, n, seq, st, left, right):
        if left == n and right == n:
            seq.append(st)
            return seq
        elif left == n:
            st1 = st + ')'
            seq = self.generate(n, seq, st1, left, right+1)
        elif left < n:
            if left > right:
                st1 = st + ')'
                seq = self.generate(n, seq, st1, left, right + 1)
            st1 = st + '('
            seq = self.generate(n, seq, st1, left + 1, right)
        return seq
    def generateParenthesis(self, n):
        seq = []
        st = ''
        return self.generate(n, seq, st, 0, 0)