// 17CSE1029 - ARCHIT

//Given a list of n-1 integers and these integers are in the range of 1 to n. There are no
//duplicates in list. One of the integers is missing in the list. Write a code to find the missing
//integer.

#include <stdio.h>
#include <stdlib.h>

// Function to check the Missing Number
int Missing_ele(int *A, int n)
{
	int sum=0;
	int i;

	for(i=1;i<=n;i++)
	{
		sum = sum + i;   // Calculating the sum of 1 to n integers
	}

	for(i=0;i<(n-1);i++)
	{
		sum = sum - *(A+i);   // Substracting the elements of the Array from this Number
	}

	int Missing_Element;
	Missing_Element = sum;
	return Missing_Element;

}

int main()
{
	int i,n;

	printf("Enter the number of Elements to be Entered\n");
	scanf("%d", &n);

	int *A = (int*)malloc(n*sizeof(int));

	printf("Enter the Elements of Array\n");

	for(i=0;i<(n-1);i++)
	{
		scanf("%d", &A[i]);
	}

	int Num;
	Num = Missing_ele(A,n);
	printf("\nMissing Element: %d\n\n", Num);
}


/*
Sample:
Input:
Enter the number of Elements to be Entered
7
Enter the Elements of Array
1
7
5
4
3
6

Output:
Missing Element: 2
*/
