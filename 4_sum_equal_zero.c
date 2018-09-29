// To Find the sub array with the sum equal to zero
#include<stdio.h>
#include<stdlib.h>
void sum_equal_zero(int A[], int n) {
  int i,j;
  for(i=0;i<n;i++) {
    int sum = 0;           // Intialize the sum = 0
    for(j=i;j<n;j++) {
      sum = sum + A[j];
      if(sum == 0)         // If sum = 0 then print starting and last index
      {
        printf("Sub Array with zero sum from index %d to %d\n", i, j);
      }
    }
  }
}
int main()
{
  int i,n;
  printf("Enter the number of Elements to be Entered\n");
  scanf("%d", &n);
  int *A = (int*)malloc(n*sizeof(int));
  printf("Enter the Elements of Array\n");
  for(i=0;i<n;i++)
  {
    scanf("%d", &A[i]);
  }
  sum_equal_zero(A,n);
  return 0;
}
