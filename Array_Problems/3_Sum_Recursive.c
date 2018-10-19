// 17CSE1029 - ARCHIT

// To Find the sum of the integers from 1 through n. Using recursion.

#include <stdio.h>

// Function to compute the sum of first n Integers
// Here i use long long in data type to Calculating sum of large till large values of n
long long int Sum(long long int n)
{
	if(n > 0)
		return n + Sum(n-1);       // Decrement in value of n to find sum using recursion.

	return n;
}

int main()
{
	long long int n;

	printf("Enter the n value: ");
	scanf("%lld", &n);

	printf("\nThe sum of the integers from 1 through %lld : %lld\n\n", n , Sum(n));
	return 0;
}

/*
Sample 1:
Input:
Enter the n value: 8


Output:
The sum of the integers from 1 through 8 : 36

------------------------------------------------------------------

Sample 2:
Input:
Enter the n value: 78945

Output:
The sum of the integers from 1 through 78945 : 3116195985

*/
