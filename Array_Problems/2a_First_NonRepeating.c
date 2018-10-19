// To find the first non- repeating element in array

#include <stdio.h>
#include <stdlib.h>
// Function used to find first non - repeating element
int First_NonRepeating(int A[], int n)
{
	int i, j;
	printf("The First Non repeating elements is: \n");
	// Traversing the array
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (i != j && A[i] == A[j])
				break;
			}
			if (j == n) {
				return A[i];
			}
		}
	return -1;
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
	int rep = First_NonRepeating(A, n);            // Calling of Function
	printf("%d\n",rep);
	return 0;
}
