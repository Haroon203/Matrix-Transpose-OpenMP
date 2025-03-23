#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h> // Include OpenMP library
#define N 1000     // Define Matrix size 1000x1000
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
// Function to perform parallel matrix transposition
void transposeParallel(int matrix[N][N], int transposed[N][N], int use_dynamic)
{
    if (use_dynamic) // If dynamic scheduling is selected
    {
#pragma omp parallel for schedule(dynamic, chunk_size) collapse(2) // Parallel loop using OpenMP with dynamic scheduling
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                transposed[j][i] = matrix[i][j];
            }
        }
    }
    else // If static scheduling is selected
    {
#pragma omp parallel for schedule(static, chunk_size) collapse(2)
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                transposed[j][i] = matrix[i][j];
            }
        }
    }
}
int main()
{
    int matrix[N][N];
    generateMatrix(matrix);
    int transposed[N][N];
    omp_set_num_threads(8); // Set number of threads to 4

    int use_dynamic = 0; // Set to 1 for dynamic, 0 for static 
    int chunk_size = 50; // chunk size

    double start = omp_get_wtime(); // Record start time
    transposeParallel(matrix, transposed, use_dynamic);
    double end = omp_get_wtime(); // Record end time
    double execution_time = end - start;                  // Calculate execution time for this run         
    printf("Execution Time: %f seconds\n", execution_time); // Print execution time for each run
    return 0;
}
