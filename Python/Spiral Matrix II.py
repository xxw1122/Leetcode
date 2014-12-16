class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
        seq = [[0 for col in range(n)] for row in range(n)]
        up = 0
        left = 0
        down = n - 1
        right = n - 1
        direct = 0
        cnt = 1
        while True:
            if direct == 0:
                for i in range(left, right+1):
                    seq[up][i] = cnt
                    cnt += 1
                up += 1
            if direct == 1:
                for i in range(up, down+1):
                    seq[i][right] = cnt
                    cnt += 1
                right -= 1
            if direct == 2:
                for i in range(right, left-1, -1):
                    seq[down][i] = cnt
                    cnt += 1
                down -= 1
            if direct == 3:
                for i in range(down, up-1, -1):
                    seq[i][left] = cnt
                    cnt += 1
                left += 1
            if up > down or left > right:
                return seq
            direct = (direct+1) % 4