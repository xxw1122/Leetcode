class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a list of strings
    def generate(self, s, dict, seq, res, cnt, pos, end):
        if pos == len(s) and end == len(s):
            ans = ' '.join(cnt)
            res.append(ans)
            return
        if end >= len(s):
            return
        if seq[pos] == 1 and s[pos:end+1] in dict:
            cnt.append(s[pos:end+1])
            self.generate(s, dict, seq, res, cnt, end+1, end+1)
            cnt.pop()
        self.generate(s, dict, seq, res, cnt, pos, end+1)
        return
    def wordBreak(self, s, dict):
        len1 = len(s)
        seq = [0] * (len1 + 1)
        seq[0] = 1
        for i in range(1, len1+1):
            for j in range(i+1):
                if s[j:i] in dict and seq[j] == 1:
                    seq[i] = 1
                    break
        if seq[len1] == 0:
            return []
        res = []
        cnt = []
        self.generate(s, dict, seq, res, cnt, 0, 0)
        return res