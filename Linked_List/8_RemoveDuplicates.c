// Write a RemoveDuplicates() function which takes a list sorted in increasing order and
// deletes any duplicate nodes from the list. Ideally, the list should only be traversed once.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void RemoveDuplicates() {
// curr Will point to Current Element in Linked_List
// Temp Node used to delete the duplicate data node
// Intial Condition if List is Empty
  NODE *curr = head;
  NODE *temp;
  if(head == NULL) {
    return;
  }
// Check if data in next of current node is equal to data in current node
// say temp to next to next node of current
// free next to current node
// link current with temp

  while(curr != NULL){
    if(curr->data == curr->next->data) {
      temp = curr->next->next;
      free(curr->next);
      curr->next = temp;
    }
    curr = curr->next;
  }
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
    printf("Enter 6 -> RemoveDuplicates\n");
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
        RemoveDuplicates();
        printf("\nAfter Removing all duplicates\n");
        Display_LL();
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
