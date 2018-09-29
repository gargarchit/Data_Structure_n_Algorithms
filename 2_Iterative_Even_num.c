// Iterative Algorithm to find the kth Even Natural Number
#include <stdio.h>

// Function to find the kth Even Natural Number
int main() {
	int k,i,num;
	printf("Enter the value of K to Find Kth even Natural Number\n");
	scanf("%d",&k);
	i = 1;
	num = 0; 
	while(i <= k) {                    //Till i is less then or equal to the entered number k it will add 2 each time
		num = num + 2;
		i++;
	}
		printf("The kth even Natural Number: %d\n", num);   // Printing the kth Even Natural Number
}
