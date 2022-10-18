"""
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

1.Each of the digits 1-9 must occur exactly once in each row.
2.Each of the digits 1-9 must occur exactly once in each column.
3.Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.


"""
board= [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]] 
def isvalid(board,row,col,c): 
    for i in range(9):
        #checking Colums 
        if board[i][col]==c: 
            return False
        #checking Rows 
        if board[row][i]==c: 
            return False
        #checking Box 
        if board[3*(row//3)+i//3][3*(col//3)+i%3]==c: 
            return False 
    return True 
def solve(board): 
    for i in range(9): 
        for j in range(9): 
            if board[i][j]=='.': 
                for c in range(1,10): 
                    if isvalid(board,i,j,str(c)): 
                        board[i][j]=str(c) 
                        if solve(board)==True: 
                            return True 
                        else: 
                            board[i][j]='.' 
                return False        
    return True 
solve(board) 
print(board)
