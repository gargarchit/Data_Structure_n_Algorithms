// Non-Recursive Algorithm to find the nth Fibonacci Number

#include <stdio.h>

int fib(int n) {
	//Declare an array to store Fibonacci numbers.
	int f[n+1];                                                       // 1 extra space for n = 0
	int i;
	f[0] = 0;	// Initial Values of Series											
	f[1] = 1;
	for (i = 2; i <= n; i++) {
		f[i] = f[i-1] + f[i-2];                                   // Add the previous 2 numbers in the series and store it
	}
	return f[n];
}
int main ()
{
	int n;
	printf("Which nth Fibonnaci Number have to print\n");
	scanf("%d",&n);
	printf("Nth Fibonacci Number is %d\n", fib(n));
	return 0;
}
