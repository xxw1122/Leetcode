class Solution:
    # @param s, a string
    # @return a list of strings
    def findRepeatedDnaSequences(self, s):
        d = {}
        for i in range(len(s) - 9):
            st = s[i:i+10]
            if st in d:
                d[st] += 1
            else:
                d[st] = 1
        res = []
        for item in d:
            if d[item] >= 2:
                res.append(item)
        return res