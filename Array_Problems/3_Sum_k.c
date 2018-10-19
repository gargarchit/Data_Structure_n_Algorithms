// Find two elements in the array such that their sum is equal to given element k.

#include <stdio.h>
#include <stdlib.h>
// Function to swap two variable
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
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
	int pi = partition(arr, low, high);
	quickSort(arr, low, pi - 1);
	quickSort(arr, pi + 1, high);
	}
}

// Function to find the two Elements such that their sum is equal to given element k
void Sum_k(int A[], int size, int k)
{
	quickSort(A,0,size);                       //Quick sort is used to sort the elements of array
	int first_i = 0;
  int last_i = size-1;
	while(first_i < last_i)                   // Loop will transerse till first_i = last_i
	{
		int t;
		t = A[first_i] + A[last_i];
    if(t == k)				// Will print the value
		{
			printf("The two elements are : %d and %d \n", A[first_i], A[last_i]);
		}
		if(t < k)
			first_i++;
		else
			last_i--;
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
	int k;
	printf("Enter The Element k:\n");
	scanf("%d", &k);
	Sum_k(A, n, k);                           // Returning Two elements of Array
	return 0;
}
