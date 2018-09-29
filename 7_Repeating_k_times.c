// 17CSE1029 - ARCHIT

//Given a list of N integers A = [a 1 , a 2 ,..., a N ], you have to find those integers which are
//repeated at least K times. In case no such element exists you have to print -1. If there
//are multiple elements in A which are repeated at least K times, then print these elements
//ordered by their first occurrence in the list.

#include <stdio.h>
#include <stdlib.h>
// Function used to find first Duplicate element
void Duplicates(int A[], int size, int k)
{
	int i, j;
	int count;
	printf("\nElements which are Repeating %d times are\n", k);
	// Traversing the array to find the Duplicate numbers
	// Here I simply check the next element of ith element and count this and make it zero
	// Then print the element which is positive and is counted k times.
	for (i = 0; i < size-1; i++)
	{
		count = 1;
		for(j =i+1; j <size; j++)
		{
			if(A[i] == A[j])
			{
				count++;
				A[j] = A[j]*0;
			}
		}
		if(count >= k && A[i] > 0) {
			printf("%d\t", A[i]);
		}
	}
	printf("\n");
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
	int k;
	printf("Enter the Value of k\n");
	scanf("%d", &k);

	Duplicates(A, n, k);            // Calling of Function
	return 0;
}
