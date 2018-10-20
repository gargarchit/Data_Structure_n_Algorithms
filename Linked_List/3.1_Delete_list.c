// Write a function DeleteList() that takes a list, deallocates all of its memory and sets its head pointer
// to NULL (the empty list).

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void DeleteList() {
  if(head == NULL) {
    printf("\nError: Linked_List already is Empty\n");
    return;
  }
  NODE *temp = head;             // dereference head to get the head on temp NODE
  NODE *temp1;                   // This will point to next NODE of temp therefore we can access next NODE
  while(temp != NULL) {          // Traverse the Linked List till last NODE
    temp1 = temp->next;          // As if I free this temp memory then List will Delete without
    free(temp);                  // deallocating the memory of Other NODEs
    temp = temp1;
  }
  printf("\n-------------------------\n");
  printf("\n Linked_List is Deleted \n");
  printf("\n-------------------------\n");
  head = NULL;
  return;
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
    printf("Enter 6 -> To Delete a List\n");
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
        DeleteList();
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
