// Given n × n matrix, and in each row all 1’s are followed 0’s.
// Find row with maximum number of 0’s.
#include <stdio.h>
#define n 4
int Row_with_Max_0(int Mat[n][n]) {
	int i = 0, j = n-1;
	int Max_0_row = 0;
	while( i < n && j > 0 )
	{
		if ( Mat[i][j] == 0 )    // Checking the Element is zero or not
		{
 			j--;                   // if zero then traverse back to previous column
			Max_0_row = i;
    }
		else {
			i++;                  // else go to next row
		}
	}
	return i;
}
int main()
{
	int Mat[n][n] = { {1, 1, 0, 0},
										{1, 1, 1, 0},
										{1, 0, 0, 0},
										{1, 1, 1, 1}};
	printf("Index of row with maximum 0s is %d ", Row_with_Max_0(Mat));
	return 0;
}
