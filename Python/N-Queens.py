
class Solution:
    # @return a list of lists of string
    def generate(self, pos, n, seq, vis, res):
        if pos == n:
            cnt = []
            for i in range(n):
                st = ""
                for j in range(n):
                    if seq[i][j] == 0:
                        st += "."
                    else:
                        st += "Q"
                cnt.append(st)
            res.append(cnt)
            return
        for i in range(n):
            if not vis[0][i] and not vis[1][pos + i] and not vis[2][pos - i + n]:
                vis[0][i] = vis[1][pos + i] = vis[2][pos - i + n] = 1
                seq[pos][i] = 1
                self.generate(pos+1, n, seq, vis, res)
                seq[pos][i] = 0
                vis[0][i] = vis[1][pos + i] = vis[2][pos - i + n] = 0
        return
    def solveNQueens(self, n):
        seq = [[0 for col in range(n)] for row in range(n)]
        vis = [[0 for col in range(30)] for row in range(3)]
        res = []
        self.generate(0, n, seq, vis, res)
        return res