class Solution:
    # @return a list of strings, [s1, s2]
    def generate(self, digits, pos, st, seq, res):
        if pos == len(digits):
            res.append(st)
            return
        for i in range(len(seq[int(digits[pos]) - 2])):
            s = st + seq[int(digits[pos]) - 2][i]
            self.generate(digits, pos + 1, s, seq, res)
        return
    def letterCombinations(self, digits):
        seq = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        res = []
        st = ""
        self.generate(digits, 0, st, seq, res)
        return res