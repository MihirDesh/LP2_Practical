#include <iostream>
using namespace std;

int N;
int board[100][100];

bool isPossible(int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }
    for (int i = row, j = col; i < N, j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveNQueens(int col)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isPossible(i, col))
        {
            board[i][col] = 1;

            if (solveNQueens(col + 1))
                return true;

            board[i][col] = 0;
        }
    }
    return false;
}