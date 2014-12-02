#!/usr/bin/env python

def isValidSudoku(self, board):
    for i in range(9):
        seq = [0] * 10
        for j in range(9):
            if board[i][j] == '.':
                continue
            if seq[int(board[i][j])] != 0:
                return False
            else:
                seq[int(board[i][j])] = 1
    for i in range(9):
        seq = [0] * 10
        for j in range(9):
            if board[j][i] == '.':
                continue
            if seq[int(board[j][i])] != 0:
                return False
            else:
                seq[int(board[j][i])] = 1
    for i in range(9):
        x = i % 3
        y = i / 3
        seq = [0] * 10
        for j in range(3):
            for k in range(3):
                dx = x * 3 + j
                dy = y * 3 + k
                if board[dx][dy] == '.':
                    continue
                if seq[int(board[dx][dy])] != 0:
                    return False
                else:
                    seq[int(board[dx][dy])] = 1
    return True