#!/usr/bin/env python

def pow(self, x, n):
    if n < 0:
        return 1/(self.pow2(x, n))
    else:
        return self.pow2(x, n)
def pow2(self, x, n):
    if n == 0:
        return 1
    elif n == 1:
        return x
    cnt = self.pow2(x, n/2)
    if n % 2 == 0:
        return cnt * cnt
    else:
        return cnt * cnt * x