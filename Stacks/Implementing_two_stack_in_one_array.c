#include <stdio.h>
#include <stdlib.h>

#define size 5
int top1 = -1;
int top2 = size;

// Here if top1 and top2 are together then stack is Full otherwise
// For stack 1 enter element from front
// For stack 2 enter element from back

int push(int *A,int ele,int stack) {
  if(abs(top1-top2)!=1) {
    if(stack==1) {
      top1++;
      A[top1]=ele;
    }
    else if(stack==2)
    {
      top2--;
      A[top2]=ele;
    }
    else {
      return 0;
    }
  }
  else {
    printf("\nArray is Full\n");
    return -1;
  }
}

// Here if top is not Null then pop the element
// from front for stack 1
// from end for stack 2

int pop(int *A,int stack,int ni) {
  if(stack==1) {
    if(top1==-1) {
      printf("Error: Underflow\n");
    }
    else
    {
      return(A[top1--]);
    }
  }
  else if(stack==2) {
    if(top2==ni)
    printf("Error: Underflow\n");
    else {
      return(A[top2++]);
    }
  }
}

// Here if stack 1 is not empty print Element in stack
// similar for stack 2

void display(int *A,int stack) {
  int i;
  if(stack==1) {
    if(top1==-1) {
      return;
    }
    else {
      printf("| %d |\n",A[top1--]);
      printf("|___|\n");
      display(A,1);
    }
  }
  if(stack==2)
  {
    if(top2==5) {
      return;
    }
    else {
      printf("| %d |\n",A[top2++]);
      printf("|___|\n");
      display(A,2);
    }
  }
}



int main()
{
  int n,ele,stack,sd,ch;
  int *A=(int*)malloc(size*sizeof(int));
  do
  {
    printf("Enter stack 1 / 2 : \n");
    scanf("%d",&stack);
    printf("Enter element (For quit pushing Elements = -1): \n");
    scanf("%d",&ele);
    if(ele==-1) {
      break;
    }
    int ans=push(A,ele,stack);
    printf("Want to pop :1 / else: 0: \n");
    scanf("%d",&ch);
    if(ch==1) {
      printf("\nFrom which stack You want to pop: \n");
      scanf("%d",&stack);
      pop(A,stack,5);
    }
    if(ans==-1) {
      break;
    }
  }
  while(ele!=-1);
  printf("\nstack 1: \n");
  display(A,1);
  printf("\nstack 2: \n");
  display(A,2);
}
