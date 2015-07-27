#!/usr/bin/env python

def addBinary(self, a, b):
    c = ""
    a = a[::-1]
    b = b[::-1]
    cnt = 0
    pos = 0
    while pos < len(a) and pos < len(b):
        ans = int(a[pos]) + int(b[pos]) + cnt
        if ans >= 2:
            cnt = ans / 2
            c += (str(ans % 2))
        else:
            c += (str(ans))
            cnt = 0
        pos = pos + 1
    while pos < len(a):
        ans = cnt + int(a[pos])
        if ans >= 2:
            cnt = ans / 2
            c += (str(ans % 2))
        else:
            c += (str(ans))
            cnt = 0
        pos = pos + 1
    while pos < len(b):
        ans = cnt + int(b[pos])
        if ans >= 2:
            cnt = ans / 2
            c += (str(ans % 2))
        else:
            c += (str(ans))
            cnt = 0
        pos = pos + 1
    if cnt == 1:
        c += str(cnt)
    c = c[::-1]
    return c