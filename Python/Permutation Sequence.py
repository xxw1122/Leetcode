class Solution:
    # @return a string
    def factorial(self, num):
        if num <= 1:
            return 1
        cnt = 1
        for i in range(1,num+1):
            cnt *= i
        return cnt

    def get(self, vis, pos):
        cnt = 0
        for i in range(len(vis)):
            if pos == cnt and vis[i] == 0:
                return i + 1
            if vis[i] == 0:
                cnt += 1

    def getPermutation(self, n, k):
        vis = [0] * n
        s = ""
        num = 0
        while num < n:
            cnt = self.factorial(n - num - 1)
            res = k / cnt
            if k / cnt != 0 and k % cnt == 0:
                res -= 1
            k -= res * cnt
            ans = self.get(vis, res)
            s += str(ans)
            vis[ans-1] = 1
            num += 1
        return s