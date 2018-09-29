//We are given a list of n-1 integers and these integers are in the range of 1 to n. There are
//no duplicates in list. One of the integers is missing in the list. Given an algorithm to find
//the missing integer.

#include <stdio.h>
#include <stdlib.h>
// Function to check the Missing Number
int Missing(int *A, int n)
{
	int sum;
	int i;
        sum = n*(n+1)/2;             // Formula to found the sum of n numbers
        for(i=0;i<(n-1);i++)
        {
                sum = sum - *(A+i);   // Substracting the elements of the Array from this Number
        }
        int MissingElement;
        MissingElement = sum;
	return MissingElement;

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
	Num = Missing(A,n);
	printf("%d", Num);
}

