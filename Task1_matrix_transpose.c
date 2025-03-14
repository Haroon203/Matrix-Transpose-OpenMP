#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000 //  define Matrix size 1000x1000

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
// It used to measure the current CPU time in seconds

double getTime()
{
    return (double)clock() / CLOCKS_PER_SEC;
}
int main()
{
    srand(time(NULL));
    int matrix[N][N];
    generateMatrix(matrix);
    int transposed[N][N];
    transposeSequential(matrix, transposed);
    
    double start = getTime(); // Record start time
    transposeSequential(matrix, transposed);
    double end = getTime();                       // Record end time
    double exection_time = end - start;             // Calculate execution time for this run 
    printf("Execution Time: %f seconds\n", exection_time); // Print execution time
    return 0;
}
