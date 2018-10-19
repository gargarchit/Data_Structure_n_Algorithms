// An algorithm for finding the first element in the array
// which is repeated

#include <stdio.h>
#include <stdlib.h>
// Function used to find first Duplicate element
void First_Duplicate(int A[], int size)
{
	int i, j;
	printf("The First repeating elements is: \n");
	// Traversing the array to find the First Duplicate number
	for (i = 0; i < size-1; i++)
	{
		for(j =i+1; j <size; j++)
			{
				if(A[i] == A[j])
				{
					printf(" %d ",A[i]);
					return;                          // return the loop when we get first Duplicate Element
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
	First_Duplicate(A, n);            // Calling of Function
	return 0;
}
