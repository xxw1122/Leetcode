class Solution:
    # @param s, a string
    # @return a list of strings

    def getIP(self, currIP, s, currIndex):
        if currIndex == 3:
            if len(s) > 0:
                if str(int(s)) == s and int(s) <= 255:
                    Solution.res.append(currIP + s)
            return
        length = len(s)
        for i in xrange(1,4):
            if length >= i and str(int(s[0:i])) == s[0:i] and int(s[0:i]) <= 255:
                self.getIP(currIP + s[0:i] + '.', s[i:], currIndex + 1)
        return

    def restoreIpAddresses(self, s):
        Solution.res = []
        self.getIP('', s, 0)
        return Solution.res