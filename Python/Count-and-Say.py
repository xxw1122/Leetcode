#!/usr/bin/env python

def generate(self, s):
    cnt = 1
    ans = s[0]
    seq = ''
    if len(s) == 1:
        seq += str(cnt)
        seq += s[0]
        return seq
    for i in range(1,len(s)):
        if s[i] == ans:
            cnt = cnt + 1
        else:
            seq += str(cnt)
            seq += ans
            cnt = 1
            ans = s[i]
        if i == (len(s) - 1):
            seq += str(cnt)
            seq += s[i]
    return seq
def countAndSay(self, n):
    s = '1'
    count = n - 1
    while count > 0:
        cnt = self.generate(s)
        count = count - 1
        s = cnt
    return s