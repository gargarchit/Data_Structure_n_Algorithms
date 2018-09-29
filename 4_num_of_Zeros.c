// 17CSE1029 - ARCHIT

//Count the number of zeros in an array of integers using recursion.

#include <stdio.h>
#include <stdlib.h>

//Function to Count Number of zeros
int Count_Zeros(int A[], int n, int count) {
  if(n-1 >= 0) {
    if(A[n-1] == 0) {
      count++;
      return Count_Zeros(A, n-1, count);
    }
    else {
      return Count_Zeros(A, n-1, count);
    }
  }
  return count;
}

int main()
{
	int i,n;

	printf("Enter the number of Elements to be Entered\n");
	scanf("%d", &n);

	int *A = (int*)malloc(n*sizeof(int));

	printf("Enter the Elements of Array \n");

	for(i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}
  int count;
  count = Count_Zeros(A,n,0);
  printf("\nNumber of Zeros in the array: %d\n\n", count);
  return 0;
}

/*
Sample:
Input:
Enter the number of Elements to be Entered
9
Enter the Elements of Array
0
0
0
0
0
0
7
8
9

Output:
Number of Zeros in the array: 6
*/
