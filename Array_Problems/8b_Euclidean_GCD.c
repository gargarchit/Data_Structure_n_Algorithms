// Euclidean algorithm to compute the GCD of two numbers
#include <stdio.h>
// Function to return GCD of a and b
int GCD_Func(int a, int b)
{
	if (a == 0)
		return b;                          // The algorithm stops when we find remainder of b/a = 0
	else
		return GCD_Func(b%a, a);           // If we Divide smaller number from larger (we reduce larger number), GCD doesn’t change
}
int main()
{
	int a, b, GCD;
	printf("Enter the two Numbers:\n");
	scanf("%d %d", &a, &b);
	GCD = GCD_Func(a,b);                 // Calling the GCD_Func
	printf("GCD of Entered Two Number is %d\n",GCD);   // Printing the GCD of the Entered 2 Numbers
	return 0;
}
 
