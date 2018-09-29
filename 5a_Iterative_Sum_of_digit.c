// Sum of digits of the 7-digit number:
// Without using recursion

#include <stdio.h>
// Function to Find the sum of digit without using Recursion
int Sum(int n) {
	int Sum_of_digit = 0;                           //Intialize the Sum_of_digit to zero
	int digit;                                    //To store the last Digit of 7-Digit Number
	while(n > 0)
	{
		digit = n%10;                         // Take Mod of input number n by 10 to get remainder
		Sum_of_digit = Sum_of_digit + digit;      // add the remainder to Sum_of_digit
		n/=10;                                // Divide the input number by 10 to get Quotient
	}
	return Sum_of_digit;                            // Returning Sum_of_digit after repeating steps till Quotient became zero
}
int main() {
	int num;
	printf("Enter a 7-digit Number:\n");
	scanf("%d", &num);
	Sum(num);
	printf("Sum of digits of the 7-digit number: %d\n", Sum(num));
	return 0;
}
