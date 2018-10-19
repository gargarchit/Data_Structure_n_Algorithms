// 17CSE1029 - ARCHIT

// Given a sorted array and a target value, find the first element that is strictly smaller than
// given element.

#include <stdio.h>
#include <stdlib.h>

//Trivial Function find the first element that is strictly smaller than
// given element.
/*int Strictly_smaller_num_trivial(int A[], int n, int k) {
	int i;
	for(i=0;i<n;i++) {
		if(A[i]==k || (A[i] > k && A[i - 1] < k ) ) {
			return A[i-1];
			break;
		}
}
}*/

//Efficient Function find the first element that is strictly smaller than
// given element.
// Using Binary Search Concept.
int Strictly_smaller_num(int A[], int first, int last, int k) {
	if(A[first] > k ) {
		printf("No Smaller Element then target Element present\n");
		return -1;
	}
	else if(A[last] < k) {
		return A[last];
	}
	else {
		while(last>=first)
		{
			int middle = (first + last)/2;
			if(A[middle]==k || (A[middle] > k && A[middle - 1] < k )) {
				return A[middle-1];
			}

// Above I created it like that if in case targeted element is not from the given elements
// Then also it will find first element that is strictly smaller than targeted Value
// By checking after dividing matrix if middle element  is equal to targeted element
// or if middle is greater but middle - 1 element is smaller then it will return next element

			else if(A[middle]>k){
				return Strictly_smaller_num(A, first, middle-1, k);
			}
			else
				return Strictly_smaller_num(A, middle+1, last, k);
			}
	}
}

int main()
{
	int i,n;

	printf("Enter the number of Elements to be Entered\n");
	scanf("%d", &n);

	int *A = (int*)malloc(n*sizeof(int));

	printf("Enter the Elements of Array (sorted)\n");

	for(i=0;i<n;i++)
	{
		scanf("%d", &A[i]);
	}

	int target_value;
	printf("\nEnter the Target Value:");
	scanf("%d", &target_value);

	int Num;
	Num = Strictly_smaller_num(A, 0, n-1, target_value);
	printf("\n\nThe first element that is strictly smaller than %d: %d\n\n", target_value, Num);

	return 0;
}


/*
Sample:
Input:
Enter the number of Elements to be Entered
7
Enter the Elements of Array (sorted)
1
4
7
8
14
18
20

Enter the Target Value:10

Output:
The first element that is strictly smaller than 10: 8

*/
