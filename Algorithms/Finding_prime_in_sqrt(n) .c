#include <stdio.h>
#include <math.h>
int main() {
  printf("\nEnter The Positive Integer, n\n");
  int n;
  scanf("%d", &n);
  int i;
  int count = 0;
  if (n == 0 || n == 1) {
    printf("n is not a Prime Number\n");
  }
    for(i = 2; i <= sqrt(n); i++ ) {
      if(n%i == 0 && n>2) {
        printf("n is not a Prime Number\n");
        count++;
      }
    }
    if(count == 0 && n> 2) {
      printf("n is a Prime Number\n");
    }

}
