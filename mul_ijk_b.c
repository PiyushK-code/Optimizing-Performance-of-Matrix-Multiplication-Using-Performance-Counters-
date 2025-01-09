#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define SIZE 2048 // Adjust according to the matrix size you want to test

double *A, *B, *C;

void allocate_matrices() {
    A = (double *)mmap(NULL, SIZE * SIZE * sizeof(double), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB, -1, 0);
    B = (double *)mmap(NULL, SIZE * SIZE * sizeof(double), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB, -1, 0);
    C = (double *)mmap(NULL, SIZE * SIZE * sizeof(double), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_HUGETLB, -1, 0);

    if (A == MAP_FAILED || B == MAP_FAILED || C == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
}

void matrix_multiplication_ijk() {
    int i, j, k;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            C[i * SIZE + j] = 0;
            for (k = 0; k < SIZE; k++) {
                C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
            }
        }
    }
}

int main() {
    allocate_matrices();
    
    // Initialize matrices A and B
    for (int i = 0; i < SIZE * SIZE; i++) {
        A[i] = i % 100;
        B[i] = i % 100;
    }

    // Perform matrix multiplication
    matrix_multiplication_ijk();

    // Free the allocated memory
    munmap(A, SIZE * SIZE * sizeof(double));
    munmap(B, SIZE * SIZE * sizeof(double));
    munmap(C, SIZE * SIZE * sizeof(double));

    return 0;
}
