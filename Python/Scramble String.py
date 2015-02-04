class Solution:
    # @return a boolean
    def isScramble(self, s1, s2):
        if s1 == s2:
            return True
        new_s1 = sorted(s1)
        new_s2 = sorted(s2)
        if new_s1 != new_s2:
            return False
        length = len(s1)
        for i in range(1, len(s1)):
            if self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:]):
                return True
            if self.isScramble(s1[:i],s2[length-i:]) and self.isScramble(s1[i:],s2[:length-i]):
                return True
        return False