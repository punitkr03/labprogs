//Program to multiply two matrices
#include <stdio.h>

int main() {
    int n=3, i, j, k, temp = 1;
    int a[n][n], b[n][n], res[n][n];

    // Inputing in the matrices
    printf("Enter the elements of matrix 2:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            a[i][j] = temp;
            b[i][j] = temp;
            temp++;
        }
    }

    // Perform matrix multiplication
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            res[i][j] = 0;
            for(k=0; k<n; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }

    // Print the result matrix
    printf("Resultant matrix:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
    return 0;
}
