class Solution:
    # @param board, a 9x9 2D array
    # Solve the Sudoku by modifying the input board in-place.
    # Do not return any value.
    def solve(self, board, x, y, vis1, vis2, vis3):
        if y >= 9:
            y = 0
            x += 1
        if x >= 9:
            return True
        while board[x][y] != '.':
            if y < 8:
                y += 1
            else:
                y = 0
                x += 1
            if x > 8:
                return True
        for i in range(1, 10):
            x1 = x / 3
            y1 = y / 3
            cnt = x1 * 3 + y1
            if vis1[x][i] == 0 and vis2[y][i] == 0 and vis3[cnt][i] == 0:
                vis1[x][i] = 1
                vis2[y][i] = 1
                vis3[cnt][i] = 1
                board[x][y] = str(i)
                if self.solve(board, x, y+1, vis1, vis2, vis3):
                    return True
                vis1[x][i] = 0
                vis2[y][i] = 0
                vis3[cnt][i] = 0
                board[x][y] = '.'
        return False

    def solveSudoku(self, board):
        vis1 = [[0 for col in range(10)] for row in range(10)]
        vis2 = [[0 for col in range(10)] for row in range(10)]
        vis3 = [[0 for col in range(10)] for row in range(10)]
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    cnt = int(board[i][j])
                    vis1[i][cnt] = 1
                    vis2[j][cnt] = 1
                    x1 = i / 3
                    y1 = j / 3
                    ans = x1 * 3 + y1
                    vis3[ans][cnt] = 1
        self.solve(board, 0, 0, vis1, vis2, vis3)
        return