#!/usr/bin/env python

class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        cnt = 1
        digits.reverse()
        for i in range(len(digits)):
            digits[i] += cnt
            if digits[i] >= 10:
                digits[i] = 0;
            else:
                cnt = 0
                break
        if cnt == 1:
            digits.append(1)
        digits.reverse()
        return digits