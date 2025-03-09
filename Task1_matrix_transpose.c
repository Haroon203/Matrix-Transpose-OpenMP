#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20 //  define Matrix size 20x20

void generateMatrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 100; // Random values store in Matrix NxN
        }
    }
}
void transposeSequential(int matrix[N][N], int transposed[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            transposed[j][i] = matrix[i][j]; // transposed of matrix row column swap
        }
    }
}

int main()
{
    srand(time(NULL));
    int matrix[N][N];
    generateMatrix(matrix);
    int transposed[N][N];
    return 0;
}
