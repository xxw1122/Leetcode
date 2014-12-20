class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def Permutation(self, num, pos, res):
        if pos == len(num):
            res.append(num[:])
            return
        for i in range(pos, len(num)):
            temp = num[i]
            num[i] = num[pos]
            num[pos] = temp
            self.Permutation(num, pos+1, res)
            temp = num[i]
            num[i] = num[pos]
            num[pos] = temp
        return
    def permute(self, num):
        if len(num) == 0:
            return []
        res = []
        self.Permutation(num, 0, res)
        return res