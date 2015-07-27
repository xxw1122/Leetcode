class Solution:
    # @return a string
    def convert(self, s, nRows):
        if len(s) == 1 or nRows == 1:
            return s
        seq = []
        for i in range(nRows):
            seq.append([])
        cnt = 0
        index = 0
        while index < len(s):
            while index < len(s) and cnt + 1 < nRows:
                seq[cnt].append(s[index])
                index += 1
                cnt += 1
            while index < len(s) and cnt - 1 >= 0:
                seq[cnt].append(s[index])
                index += 1
                cnt -= 1
        st = ""
        for i in range(len(seq)):
            for j in range(len(seq[i])):
                st += seq[i][j]
        return st