class Solution:
    # @return an integer
    def dp(self, len1, len2, word1, word2, seq):
        if seq[len1][len2] != -1:
            return seq[len1][len2]
        if len1 == 0 or len2 == 0:
            cnt = len1 - len2
            if cnt < 0:
                cnt = -cnt
            seq[len1][len2] = cnt
            return seq[len1][len2]
        if word1[len1-1] == word2[len2-1]:
            seq[len1][len2] = self.dp(len1-1, len2-1, word1, word2, seq)
        else:
            seq[len1][len2] = min(self.dp(len1-1, len2-1, word1, word2, seq),
                                  self.dp(len1-1, len2, word1, word2, seq), self.dp(len1, len2-1, word1, word2, seq)) + 1
        return seq[len1][len2]
    def minDistance(self, word1, word2):
        len1 = len(word1)
        len2 = len(word2)
        seq = [[-1 for col in range(len2+1)] for row in range(len1+1)]
        res = self.dp(len1, len2, word1, word2, seq)
        return res