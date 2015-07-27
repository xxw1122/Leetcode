#!/usr/bin/env python


def longestCommonPrefix(self, strs):
    s = ''
    num = 0
    if len(strs) == 0:
        return s
    elif len(strs) == 1:
        return strs[0]
    while num >= 0:
        if num >= len(strs[0]):
            return s
        ch = strs[0][num]
        for i in range(1, len(strs)):
            if num >= len(strs[i]):
                return s
            elif strs[i][num] != ch:
                return s
        s += ch
        num += 1
    return s