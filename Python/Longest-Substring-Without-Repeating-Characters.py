class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        len1 = len(s)
        sublen = 0
        seq = []
        index = 0
        while index < len1:
            if s[index] not in seq:
                seq.append(s[index])
                sublen = max(sublen, len(seq))
                index += 1
            else:
                seq.pop(0)
        return sublen