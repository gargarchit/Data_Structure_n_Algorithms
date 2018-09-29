// Fibonacci (n) using recursion
// Print how many calls are required for obtaining this nth number in the series

#include <stdio.h>
int Call_Counter = 0; 					   // Global Variable to find the Number of calls required
// Function to Find Fibonacci (n) using Recursion
int fib(int n)
{
	Call_Counter++;
	if(n<=1)
		return n;				   // For First Two Number of Series
	else
	{
		return fib(n-1) + fib(n-2);                // Recursive call of the Fibonacci Function
	}
}
int main()
{
	int n, a;
	printf("Write the Value Of N\n");
	scanf("%d", &n);                                   // getting the Number as Input   
	a=fib(n);                                          // Calling above function to find Binary Equivalent of the number
	printf("Nth Fibonacci Number: %d ",a);            // Printing the Binary Equivalent of the Number
	printf("is Obtained in %d Calls\n",Call_Counter);  // Printing Numbers Of Calls
	return 0;
}

