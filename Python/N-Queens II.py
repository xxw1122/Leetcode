class Solution:
    # @return an integer
    def generate(self, pos, n, vis, res):
        if pos == n:
            res += 1
            return res
        for i in range(n):
            if not vis[0][i] and not vis[1][pos + i] and not vis[2][pos - i + n]:
                vis[0][i] = vis[1][pos + i] = vis[2][pos - i + n] = 1
                res = self.generate(pos+1, n, vis, res)
                vis[0][i] = vis[1][pos + i] = vis[2][pos - i + n] = 0
        return res
    def totalNQueens(self, n):
        vis = [[0 for col in range(30)] for row in range(3)]
        res = 0
        return self.generate(0, n, vis, res)