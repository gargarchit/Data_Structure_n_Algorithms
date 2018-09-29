//Given an array of positive integers, all numbers occurs even number of times except
//one number which occurs odd number of times. Find the number in O(n) time.

#include <stdio.h>
#include <stdlib.h>
// Function to swap two variable
// Here on Appling XOR operator when it encounter same number again it became zero
// else it will return the same value
// Therefore he we can transverse the complete array
// For all Even occurance of Element it became zero
// and for odd occurance of Element it return that Element

int Element_odd_times(int A[], int size)
{
    int i;
    int result = 0;
    for (i = 0; i < size; i++)
        result = result ^ A[i];

    return result;
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
  int Num=Element_odd_times(A,n);
  printf("Element which occur odd no of times : %d\n",Num);                         // Returning Element which occurs odd Number of times
	return 0;
}
