// An algorithm for finding the element which
// appears maximum number of times in the array

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
// Function for finding the element which
// appears maximum number of times in the array
int Max_Repeating(int A[], int size)
{
	quickSort(A, 0, size-1);                     // Quick sort is used to sort the elements of array
	int i;
  int max_repeat = 0, max_repeat_i = 0;
	int count;
	for(i=0;i<size-1;i++)
	{
		count = 0;
		while(A[i] == A[i+1])
		{
			count++;
			i++;
		}
		if(count > max_repeat)
		{
			max_repeat = count;
			max_repeat_i = i;
		}
	}
	return A[max_repeat_i];
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
	int Max_r = Max_Repeating(A, n);
	printf("%d", Max_r);
	return 0;
}
