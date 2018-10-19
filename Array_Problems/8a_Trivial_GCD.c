// To compute the greatest common divisor (GCD) of any two numbers
// Trivial Approach
#include <stdio.h>
// Function to compute the greatest common divisor (GCD) of two numbers
int GCD_Func(int a, int b) {
	int i, gcd;
	for(i=1;i<=a && i<=b;i++)
	{
        	if(a%i==0 && b%i==0)         // if both a and b are exactly divisible by i, the value of i is assigned to gcd
            	gcd = i;
    	}
	return gcd;
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


