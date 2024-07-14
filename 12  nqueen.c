#include <stdio.h>
#include <stdlib.h>

#define N 4// Change this value for different board sizes

void disp(int board[N][N])
{
    static int k = 1;
    printf("Solution %d:\n", k++);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

void solveNQ(int board[N][N], int col)
{
    if (col >= N)
    {
        disp(board);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            solveNQ(board, col + 1);
            board[i][col] = 0; // BACKTRACK
        }
    }
}

int main()
{
    int board[N][N] = {0};
    solveNQ(board, 0);
    return 0;
}
