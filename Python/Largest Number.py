class Solution:
    # @param num, a list of integers
    # @return a string
    def cmp1(self, x, y):
        if x + y > y + x:
            return 1
        else:
            return -1
    def largestNumber(self, num):
        seq = []
        for item in num:
            seq.append(str(item))
        seq.sort(self.cmp1)
        return str(int(''.join(seq)))