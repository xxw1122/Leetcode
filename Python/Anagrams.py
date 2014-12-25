class Solution:
    # @param strs, a list of strings
    # @return a list of strings
    def anagrams(self, strs):
        d = {}
        for item in strs:
            ans = list(item)
            ans.sort()
            s = "".join(ans)
            if s not in d:
                d[s] = []
            d[s].append(item[:])
        seq = []
        for item in d:
            if len(d[item]) >= 2:
                seq += d[item]
        return seq