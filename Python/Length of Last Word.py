#!/usr/bin/env python

def lengthOfLastWord(self, s):
    seq = s.spilt()
    if len(seq) == 0:
        return 0
    else:
        return len(seq[len(seq) - 1])