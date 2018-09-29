// Let A be an array of n distinct integers. Suppose A has the following property: there
// exists an index 1≤ k ≤ n such that A[1], . . . , A[k] is an increasing sequence and
// A[k+1], . . . ,A[n] is a decreasing sequence. Design an algorithm for finding k.
#include <stdio.h>
#define SIZE 10
// Function to find Max element
int Maximum(int A[], int first, int last) {
  if (first == last)                           // Checking the case when there is only 1 element
    return A[first];
  if ((last == first + 1) && A[first] >= A[last])   // when there is only 2 Elements
    return A[first];
  if ((last == first + 1) && A[first] < A[last])
    return A[last];
  int mid = (first + last)/2;
  if (A[mid] > A[mid + 1] && A[mid] > A[mid - 1])   // if mid is the Max element
    return A[mid];
  if (A[mid] > A[mid + 1] && A[mid] < A[mid - 1])    // removing left side or right side element of mid to find max element
    return Maximum(A, first, mid - 1);
  else
    return Maximum(A, mid + 1, last);
}

int main() {
  int A[SIZE];
  int i;
	printf("Enter the Elements of Array upto 10\n");
	for(i=0;i<SIZE;i++)                                     // Getting the input array from user
	{
		scanf("%d", &A[i]);
	}
  int k;
  k = Maximum(A, 0, SIZE-1);
  printf("Value of k : %d\n", k);
  return 0;
}
