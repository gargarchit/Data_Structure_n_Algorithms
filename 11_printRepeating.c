//Given an array with n + 2 elements, all elements of the array are in range 1 to n and also
//all elements occur only once except two numbers which occur twice. Find those two
//repeating

#include<stdio.h>
#include<stdlib.h>
// Function to find the Repeating numbers
void printRepeating(int A[], int size)
{
  int *count = (int *)malloc((size - 2)*sizeof(int)); // Creating a Temporary array count to store Index
  int i;

  printf("Repeating elements are ");
  // Traverse the array once.
  for(i = 0; i < size; i++)
  {
    if(count[A[i]] == 1)           //While traversing, keep track of count of all elements in the array using a temp array count[] of size n
      printf(" %d ", A[i]);
    else
     count[A[i]]++;
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
  printRepeating(A, n);
  return 0;
}
