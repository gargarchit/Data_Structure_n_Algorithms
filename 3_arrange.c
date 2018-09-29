// Arranging the array in alternate fashion of negative and postive numbers
#include<stdio.h>
#include<stdlib.h>

void arrange(int A[], int n)
{
  printf("Output: \n");
  int* temp = (int*)malloc(n*sizeof(int));  // Create a temp array to  separate and store -ve and +ve number
  int l = 0, h = n-1;
  int a;
  for(a=0;a<n;a++) {
    if(A[a]<0)
      temp[l++] = A[a];
    else
      temp[h--] = A[a];
    }
    int neg = 0;
    int pos = n-1;
    while(neg<=l && pos>=l) {
      printf(" %d ", temp[neg++]);
      printf(" %d ", temp[pos--]);
    }
    while(neg<=l) {
      printf(" %d ", temp[neg++]);
    }
    while(pos>=l) {
      printf(" %d ", temp[pos--]);
    }
}

int main()
{
  int i,n;
  printf("Enter the number of Elements to be Entered\n");
  scanf("%d", &n);
  int *A = (int*)malloc(n*sizeof(int));
  printf("Enter the Elements of Array\n");
  for(i=0;i<n;i++)
  {
    scanf("%d", &A[i]);
  }
  arrange(A,n);
  return 0;
}
