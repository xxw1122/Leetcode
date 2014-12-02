#!/usr/bin/env python

def reverseWords(self, s):
    seq = s.split()
    seq.reverse()
    cnt = ''
    if len(seq) == 0:
        return cnt
    for i in range(len(seq) - 1):
        cnt += seq[i]
        cnt += ' '
    cnt += seq[len(seq) - 1]