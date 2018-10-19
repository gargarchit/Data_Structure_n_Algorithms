//Given an array with both positive and negative numbers. We need to find the two
//elements such that their sum is closest to zero.

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
// Function to print pair of elements having minimum sum
int Sum_closestToZero(int A[], int n)
{
  int sum, min_sum;
  int l = 0, r = n-1;           // Here l and r is 1st and last Index of an array
  int min_l = l, min_r = n-1;
  if(n < 2)                        // if only 2 elements are there
  {
    return 0;
  }

  // Sort the elements
  quickSort(A, l, r);
  while(l < r)
  {
    sum = A[l] + A[r];
    if(abs(sum) < abs(min_sum))
    {
      min_sum = sum;
      min_l = l;
      min_r = r;
    }
    if(sum < 0)
      l++;
    else
      r--;
  }

  printf(" The two elements whose sum is minimum are %d and %d",A[min_l], A[min_r]);
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
  	Sum_closestToZero(A, n);
  	return 0;
  }
