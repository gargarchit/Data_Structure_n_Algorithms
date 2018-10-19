// To remove the Duplicates

#include<stdio.h>
#include<stdlib.h>
// Function to remove Duplicates
int Duplicates(int A[], int size)
{
	int i,j=0;
  for(i=0; i < size-1; i++) {
    if (A[i] != A[i+1]) {
      A[j++] = A[i];
    }
  }
  A[j++] = A[size-1];
  return j;     // Return Lenght of New Array
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
  printf("Input Array A = ");
  for(i=0;i<n;i++)
  {
    printf(" %d ", A[i]);
  }
  printf("\n");
  n = Duplicates(A, n);
  printf("New Lenght : %d\n",n);
  printf("A is now : ");
  for(i=0;i<n;i++)
  {
    printf(" %d ", A[i]);
  }
  printf("\n");
  return 0;
}
