#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2048 // Modify this to 8192 for larger tests

void matrix_multiply(int **A, int **B, int **C) {
    int blockSize = 64; // Block size (tile size)

    // Outer loops over blocks
    for (int i = 0; i < N; i += blockSize) {
        for (int j = 0; j < N; j += blockSize) {
            for (int k = 0; k < N; k += blockSize) {
                // Inner loops within blocks
                for (int kk = k; kk < k + blockSize && kk < N; kk++) {
                    for (int ii = i; ii < i + blockSize && ii < N; ii++) {
                        for (int jj = j; jj < j + blockSize && jj < N; jj++) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }
}


int main() {
    int **A, **B, **C;
    A = (int **)malloc(N * sizeof(int *));
    B = (int **)malloc(N * sizeof(int *));
    C = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        A[i] = (int *)malloc(N * sizeof(int));
        B[i] = (int *)malloc(N * sizeof(int));
        C[i] = (int *)malloc(N * sizeof(int));
    }

    // Initialize matrices
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
        }
    }

    clock_t start = clock();
    matrix_multiply(A, B, C);
    clock_t end = clock();

    printf("Execution time: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Clean up memory
    for (int i = 0; i < N; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
