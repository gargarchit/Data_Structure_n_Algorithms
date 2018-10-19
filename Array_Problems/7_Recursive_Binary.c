// To find the binary equivalent of the number using recursion
// For instance, if the input is 9, then binary value is 1001

#include <stdio.h>
// Function to Find the binary equivalent of the number using recursion
int Binary(int n) {
	if (n == 0)
		return 0;   
	else {
		return (n % 2 + 10*Binary(n / 2));			     // Recursive call of the Function
	}
}


int main() {
	int num;
	printf("Enter a Number:\n");
	scanf("%d", &num);                                                   // getting the Number as Input                                         
	Binary(num);                                                         // Calling above function to find Binary Equivalent of the number
	printf("Binary equivalent of the Number : %d\n", Binary(num));       // Printing the Binary Equivalent of the Number
	return 0;
}

