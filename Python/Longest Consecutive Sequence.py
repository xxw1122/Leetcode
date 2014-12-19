class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        if not num:
            return 0
        seq = {}
        for i in num:
            if i not in seq:
                seq[i] = 1
        res = 1
        for i in num:
            cnt = i - 1
            cur = 1
            while cnt in seq:
                del seq[cnt]
                cnt -= 1
                cur += 1
            cnt = i + 1
            while cnt in seq:
                del seq[cnt]
                cnt += 1
                cur += 1
            res = max(res, cur)
        return res