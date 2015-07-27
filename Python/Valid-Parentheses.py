#!/usr/bin/env python

def isValid(self, s):
    length = len(s)
    seq = []
    for i in range(length):
        if s[i] == '{' or s[i] == '[' or s[i] == '(':
            seq.append(s[i])
        else:
            if s[i] == '}':
                if len(seq) >=1 and seq[len(seq) - 1] == '{':
                    seq.pop()
                else:
                    return False
            if s[i] == ']':
                if len(seq) >=1 and seq[len(seq) - 1] == '[':
                    seq.pop()
                else:
                    return False
            if s[i] == ')':
                if len(seq) >=1 and seq[len(seq) - 1] == '(':
                    seq.pop()
                else:
                    return False
    if len(seq) != 0:
        return False
    return True