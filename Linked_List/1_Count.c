//Write a Count() function that counts the number of times a given int occurs in a linked list.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void Count() {
  if(head == NULL) {
    printf("\nError: Linked_List is Empty\n");
    return;
  }
  int count = 0;   // To Count the Number of times given key aka given Integer occurs
  NODE *temp = head;  // dereference head to get the head on temp NODE
  int key;                       // Given Integer
  printf("Enter the Number\n");
  scanf("%d", &key);
  while(temp != NULL) {          // Traverse the Linked List till last NODE
    if(key == temp->data) {           // If key = data at that node execute count++ to count it
      count++;
    }
    temp = temp->next;
  }
  printf("\nThe Number of times  %d occurs: %d\n",key, count);
}

void main() {
  int a;
  while(a!=0) {
    printf("\n\n");
    printf("Enter 1 -> Insert_front\n");
    printf("Enter 2 -> Delete_front\n");
    printf("Enter 3 -> Insert_end\n");
    printf("Enter 4 -> Delete_end\n");
    printf("Enter 5 -> Display_LL\n");
    printf("Enter 6 -> Count()\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    if(a==0) {
      printf("-------------------------Thank You----------------------------\n");
      return;
    }
    switch(a) {
      case 1 :
      {
        Insert_front();
        Display_LL();
        break;
      }
      case 2 :
      {
        Delete_front();
        Display_LL();
        break;
      }
      case 3 :
      {
        Insert_end();
        Display_LL();
        break;
      }
      case 4 :
      {
        Delete_end();
        Display_LL();
        break;
      }
      case 5 :
      {
        Display_LL();
        break;
			}
      case 6 :
      {
        Count();
        break;
      }
      default :
      {
        printf("Wrong Value Detacted\n");
        break;
      }
      return;
    }
  }
}
