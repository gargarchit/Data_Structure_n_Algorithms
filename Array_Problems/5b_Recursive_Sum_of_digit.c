// Sum of digits of the 7-digit number:
// Using Recursion
#include <stdio.h>
 // Function to Find the sum of digit using recursion
int Sum(int n) {
	if (n == 0)
		return 0;                              // Terminating Condition
	else
		return (n % 10 + Sum(n / 10));         // Recursive call to add next last digit of the Number
}
 

int main() {
	int num;
	printf("Enter a 7-digit Number:\n");
	scanf("%d", &num);
	Sum(num);
	printf("Sum of digits of the 7-digit number: %d\n", Sum(num));       // Printing The Sum of Digit of the Number
	return 0;
}
