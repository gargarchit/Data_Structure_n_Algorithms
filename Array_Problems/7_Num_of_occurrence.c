// Give a sorted array of n elements, possibly with duplicates;
// find the number of occurrences of a number.
#include<stdio.h>
#include <stdlib.h>
// Function to Find occurrences of given Element
int Num_of_occurrence(int A[], int size, int k)
{
	int i;
	int count = 0;
	for(i=0;i<size;i++)
	{
		if(A[i] == k)              // Check the Element in the Array
		{
			count++;                 // Increment the counter if Element is found
		}
	}
	return count;               // Return Counter
}

int main()
{
	int i,n;
	printf("Enter the number of Elements to be Entered\n");
	scanf("%d", &n);
	int *A = (int*)malloc(n*sizeof(int));
	printf("Enter the Sorted Array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	int k;
  printf("Enter the Number:\n");
  scanf("%d", &k);
  int Num_o = Num_of_occurrence(A, n, k);
	printf("%d\n", Num_o);
	return 0;
}
