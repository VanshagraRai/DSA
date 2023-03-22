#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **board, int x, int y, int n)
{
    // For checking if Another Queen is in the same column
    for (int row = 0; row < x; row++)
        if (board[row][y] == 1)
            return false;

    // For checking the left diagonal
    int i = x;
    int j = y;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j--;
    }

    i = x;
    j = y;

    // For checking the right diagonal
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return false;
        i--;
        j++;
    }

    return true;
}

bool solveNqueen(int **board, int r, int n)
{
    if (r >= n)
        return true;

    // Trying to place the queen in the row
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, r, col, n))
        {
            board[r][col] = 1;

            // Checking if we can place the next queen in the next row
            if (solveNqueen(board, r + 1, n))
                return true;

            // If we cannot place we backtrack
            board[r][col] = 0; // Back Tracking
        }
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the size of the board: "; 
    cin >> n;

    // Initializing the board and adding 0's
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    // Calling the solveNqueen function and printing the board
    if (solveNqueen(board, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
}