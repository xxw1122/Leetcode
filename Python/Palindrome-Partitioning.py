import copy

class Solution:
    # @param s, a string
    # @return a list of lists of string
    def isPalindrome(self, s, left, right):
        if left == right:
            return True
        mid = (left + right) / 2
        for i in range(left, mid + 1):
            if s[i] != s[right - i + left]:
                return False
        return True
    def generate(self, s, pos, end, cnt, res, seq):
        if end == len(s) and pos == len(s):
            res.append(copy.copy(cnt))
            return
        if end >= len(s):
            return
        if seq[pos][end] == 1:
            cnt.append(s[pos:end+1])
            self.generate(s, end+1, end+1, cnt, res, seq)
            cnt.pop()
        self.generate(s, pos, end+1, cnt, res, seq)
        return
    def partition(self, s):
        length = len(s)
        seq = [[0 for col in range(length)] for row in range(length)]
        for i in range(length):
            for j in range(i + 1):
                if self.isPalindrome(s, j, i):
                    seq[j][i] = 1
        cnt = []
        res = []
        self.generate(s, 0, 0, cnt, res, seq)
        return res