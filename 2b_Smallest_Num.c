//  To Find the smallest positive integer value that cannot be represented as sum of any subset of a given array
#include <stdio.h>
#include <stdlib.h>
int Smallest_Num(int A[], int size)
{
  int i;
  int k = 1; // Initialize result
  // Traverse the array and increment 'k' if arr[i] is
  // smaller than or equal to 'k'.
  for(i = 0;i < size && A[i] <= k; i++)
    k = k + A[i];
  return k;
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
	int num = Smallest_Num(A, n);            // Calling of Function
  printf("Smallest_Num: \n");
  printf("%d \n", num);
  return 0;
}
