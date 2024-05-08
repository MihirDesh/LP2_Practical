#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> board;

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }
    return true;
}

bool solveNQueens()
{
    priority_queue<pair<int, vector<vector<int>>>> pq;
    pq.push({0, board});

    auto state = pq.top();
    pq.pop();

    int row = state.first;
    vector<vector<int>> currentBoard = state.second;

    if (row == N)
    {
        board = currentBoard;
        return true;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            currentBoard[row][col] = 1;

            int LB = row + 1;

            pq.push({LB, currentBoard});

            currentBoard[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout << "Enter number of queens: " << endl;
    cin >> N;

    board.assign(N, vector<int>(N, 0));

    if (!solveNQueens())
    {
        cout << "Solution does not exist" << endl;
        return 0;
    }

    cout << "Solution" << endl;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
    cout << endl;

    return 0;
}