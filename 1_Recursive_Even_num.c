// Recursive Algorithm to find the kth Even Natural Number

#include <stdio.h>
// Function to find the kth Even Natural Number
int Num(int k)
{
	if(k > 0)
		return Num(k-1) + 2; //Num is reducing and addition of 2 each time 
	else
		return 0;            //Loop Terminating Condition
}

int main()
{
	int n;
	printf("Enter the Value of K:\n ");
	scanf("%d", &n);
	printf("The kth Even Natural Number is %d\n", Num(n));               // Printing The kth Even Natural Number
	return 0;
}
