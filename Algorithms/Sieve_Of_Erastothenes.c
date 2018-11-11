// Algorithm to Find all The Prime Number before the Input Number

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
  int n;
  printf("\nEnter Value of n\n");
  scanf("%d", &n);
  int *A = (int*)malloc(n*sizeof(int));
  int i, j;
  // Intializing the Array A which will contain prime number at the end by 1 at all index
  for(i = 2; i<=n; i++) {
    A[i] = 1;
  }
  for(i = 2; i <=sqrt(n); i++ ) {
    if(A[i] == 1) {
      for(j = i*2; j <=n; j = j + i) {      //Crossing out all the multiple of i by changing its value to 0
        A[j] = 0;
      }
    }
  }
  printf("Prime Number Before %d :\n", n);
  // printing the prime Numbers
  for(i = 2; i<=n; i++) {
    if(A[i] == 1) {
      printf("%d  ", i);
    }
  }
  printf("\n");
}

// To Compile use "gcc 5_Sieve_Of_Erastothenes.c -lm"

// Time Complexity O(sqrt(n)loglogn)
