#!/usr/bin/python3
import sys


def is_valid(board, row, col, N):
    for i in range(N):
        if board[row][i] == 1 or board[i][col] == 1:
            return False
    for i in range(N):
        for j in range(N):
            if (i+j) == (row+col) or (i-j) == (row-col):
                if board[i][j] == 1:
                    return False
    return True


def n_queens(board, col, N):
    if col == N:
        for i in range(N):
            for j in range(N):
                if board[i][j] == 1:
                    print(j+1, end=' ')
        print()
        return True
    res = False
    for i in range(N):
        if is_valid(board, i, col, N):
            board[i][col] = 1
            res = n_queens(board, col+1, N) or res
            board[i][col] = 0
    return res


if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    N = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if N < 4:
    print("N must be at least 4")
    sys.exit(1)
