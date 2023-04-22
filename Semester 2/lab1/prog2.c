//Program to subtract two matrices
#include <stdio.h>

int main() {
  int n=3, i, j, temp=1;
  int a[n][n], b[n][n], sum[n][n];

  //Populating two matrices with numbers
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      a[i][j] = temp;
      b[i][j] = temp;
      temp++;
    }
  }
  // Subtract the two matrices
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      sum[i][j] = a[i][j] - b[i][j];
    }
  }

  // Display the result
  printf("\nDifference of two matrices: \n");
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      printf("%d ", sum[i][j]);
    }
    printf("\n");
  }

  return 0;
}
