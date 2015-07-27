class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def wordBreak(self, s, dict):
        len1 = len(s)
        seq = [0] * (len1 + 1)
        seq[0] = 1
        for i in range(1, len1+1):
            for j in range(i+1):
                if s[j:i] in dict and seq[j] == 1:
                    seq[i] = 1
                    break
        if seq[len1] == 1:
            return True
        else:
            return False