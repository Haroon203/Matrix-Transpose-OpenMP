#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // Include OpenMP library
#define N 20     // Define Matrix size 20x20
void generateMatrix(int matrix[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = rand() % 100; // Random values in Matrix NxN
        }
    }
}

int main()
{
    int matrix[N][N];
    generateMatrix(matrix);
    return 0;
}