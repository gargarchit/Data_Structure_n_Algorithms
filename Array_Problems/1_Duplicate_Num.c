// An algorithm for checking whether there are any
// duplicated elements in the array or not

#include <stdio.h>
#include <stdlib.h>

// Function used to swap two variable in quickSort
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int arr[], int low, int high)
{
	int pivot = arr[high];                                         // pivot
	int i = (low - 1);
	int j;
	for (j = low; j <= high- 1; j++)
	{
		if (arr[j] <= pivot)
		{
		i++;
		swap(&arr[i], &arr[j]);
		}
    	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
// Function to perform quick quickSort
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// Function two find all the Duplicate Number in the Array
void DuplicateNum(int A[], int size)
{
	int i;
	quickSort(A, 0, size-1);
	printf("The repeating elements are: \n");
	for (i = 0; i < size;)
	{
		if(A[i] == A[i+1])          // After sorting if the Element is matches with Next Element
		{                           // then this Element is Duplicate
			printf(" %d ", A[i]);
			i++;
		}
		else
		{
			i++;
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
	DuplicateNum(A, n);
	return 0;
}
