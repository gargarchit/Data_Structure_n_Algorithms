// Recursive function to compute the sum of first n Integers

#include <stdio.h>
// Function to compute the sum of first n Integers
int Sum(int n)
{
	if(n > 0)
		return n + Sum(n-1);       // Reducing value of n also adding the value of n to create Recursion
	else
		return n;
}

int main()
{
	int num;
	printf("Enter a Integer: ");
	scanf("%d", &num);
	printf("Sum of first %d Numbers is %d\n",num ,Sum(num));   // Printing the Sum of first n Integer
	return 0;
}
