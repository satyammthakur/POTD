/*
Sudoku Solver LC-37 , LC-Hard
Link: https://leetcode.com/submissions/detail/1754831905/
Prerequisties- LC 36

Concept - Recursion, Backtracking , HashMap

Backtracking - Do->Explore->Undo

Approach- what I thought of is using the knowledge of LC 36 where I had to find valid sudoku , and use recursion 
to add numbers and after adding every number i will check if it valid or not if it is valid I will def move with
it else I will just backtrack to previous state. 

But I couldn't code it so I am watching solution of code with mike.

Solution- Given that every question will have only one solution

so basically first of all we checked for every row and col therefore 2 for loops if we enocounter any '.' we will 
start inserting any digit there (1-9) so another loop for that, and we will check if inserting any digit is valid 
or not if it is valid then we will do board[i][j]=d and check if it solvabale after that if yes return true or just
undo it board[i][j]='.' if we couldn't find any digit then return false as it is not solvable and if our solve 
funtion doesn't return anything we will just return true at the end meaning we found an answer.

for writing valid function we checked row,col 
first checked col then row. 

for 3*3 subgrid, we used the concept startRow,startCol woh dekh lo.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char d) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == d)
                return false; // col check

            if (board[row][i] == d)
                return false; // row check
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[startRow + i][startCol + j] == d)
                    return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char d = '1'; d <= '9'; d++) {
                        if (isValid(board, i, j, d)) {
                            board[i][j] = d; // do
                            if (solve(board) == true) { // explore 
                                return true;
                            }
                            board[i][j]='.'; // undo
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};