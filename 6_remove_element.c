//To Remove the given Element from the array
#include <stdio.h>
#include<stdlib.h>
// Function to print Array Elements
void print_array(int *A, int n) {
  int i;
  printf("Enter the Elements of Array\n");
  for (i=0; i<n; i++) {
    scanf("%d", &*(A+i));
  }
  for (i=0; i<n; i++) {
    printf("%d\t", *(A+i));
  }
}
// To remove the Element from the array
int remove_element(int *A, int n, int k) {
  int i;
  printf("After Removing the given Element\n");
  if(k==0) // if we have to remove first one
  {
    for (i=1; i<n; i++) {
      printf("%d\t", *(A+i));
    }
  }
  else if(k==(n-1)) // if we have to remove last one
  {
    for (i=0; i<n-1; i++) {
      printf("%d\t", *(A+i));
    }
  }
  else if(k>0 && k<(n-1)) // if we have to remove any middle one
  {
    for (i=0; i<k; i++) {
      printf("%d\t", *(A+i));
    }
    for (i=k+1; i<n; i++) {
      printf("%d\t", *(A+i));
    }
  }
  printf("\n");
}
int main()
{
	int i,n,k;
	printf("Enter the number of Elements to be Entered\n");
	scanf("%d", &n);
	int *A = (int*)malloc(n*sizeof(int));
  print_array(A,n);
  printf("\nEnter the index of element\n");
  scanf("%d", &k);
  remove_element(A,n,k);
  return 0;
  }
