//To print all comman 

#include <stdio.h>
void Common_Elements(int A[], int B[], int C[], int a, int b, int c) {
  int i = 0,j = 0, k = 0;   // Intializing the Index
  // Transverse Through all three arrays simultaneously using indexes i,j,k.
  printf("Comman Elements are :\n");
  while(i<a && j<b && k<c){
    if((A[i]==B[j])&& (B[j]==C[k])){
      // if A[i]=B[j]=C[k] then print A[i]
      // do i++, j++, k++
      printf(" %d ", A[i]);
      i++;j++;k++;
    }
    // if not, Compare all A[i],B[j],C[k]
    //which ever is smaller, increase its index
    else if((A[i]<=B[j])&& (A[i]<=C[k])){
      i++;
    }
    else if((B[j]<=A[i])&& (B[j]<=C[k])){
      j++;
    }else{
      k++;
    }
  }
  printf("\n");
}
int main()
{
  // Given sorted Arrays
  int A[] = {1, 5, 10, 20, 40, 80};
  int B[] = {6, 7, 20, 80, 100};
  int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
  // Lenght of the Arrays
  int a = sizeof(A)/sizeof(int);
  int b = sizeof(B)/sizeof(int);
  int c = sizeof(C)/sizeof(int);
  Common_Elements(A,B,C,a,b,c);
}
