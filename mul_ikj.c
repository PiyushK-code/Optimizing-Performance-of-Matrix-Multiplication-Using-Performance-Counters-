#include <stdio.h>
#include <stdlib.h>
 
#define N 2048 

void multiply(int A[N][N], int B[N][N], int C[N][N])
{
 
    printf("Resultant Matrix is:\n");
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
 
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
 
        }
 
    }
}

int main(){
	int A[N][N], B[N][N], C[N][N];
	
	for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
		A[i][j] = rand()%100;
		B[i][j] = rand()%100;

		}
	}

	multiply(A,B,C);
	return 0;
}
