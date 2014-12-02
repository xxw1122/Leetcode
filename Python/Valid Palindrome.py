#!/usr/bin/env python

def isPalindrome(self, s):
    seq = ''
    for i in range(len(s)):
        if s[i].isalpha():
            seq += s[i].lower()
        elif s[i].isdigit():
            seq += s[i]
    for i in range(len(seq)/2):
        if seq[i] != seq[len(seq)-1-i]:
            return False
    return True