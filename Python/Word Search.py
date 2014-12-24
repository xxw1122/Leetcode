class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    def dfs(self, board, word, seq, pos, x, y):
        if pos == len(word):
            return True
        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]
        for i in range(4):
            x1 = x + dx[i]
            y1 = y + dy[i]
            if x1 >= 0 and x1 < len(board) and y1 >= 0 and y1 < len(board[0]) and seq[x1][y1] == 0 and board[x1][y1] == word[pos]:
                seq[x1][y1] = 1
                if self.dfs(board, word, seq, pos+1, x1, y1):
                    return True
                seq[x1][y1] = 0
        return False
    def exist(self, board, word):
        len1 = len(board)
        len2 = len(board[0])
        seq = [[0 for col in range(len2)] for row in range(len1)]
        for i in range(len1):
            for j in range(len2):
                if board[i][j] == word[0]:
                    seq[i][j] = 1
                    if self.dfs(board, word, seq, 1, i, j):
                        return True
                    seq[i][j] = 0
        return False