//Write a SortedInsert() function which given a list that is sorted in increasing order, and a single
//node, inserts the node into the correct sorted position in the list.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void SortedInsert() {
  NODE *newnode;
  newnode = getnode();

//for inserting at boundary points here I check if head data is greater then newnode data then do Insert_front

  if (head == NULL || head->data >= newnode->data) {
    newnode->next = head;
    head = newnode;
  }
// else while Current next data is less then new node data do insert after Current
  else {
    NODE *curr = head;
    while(curr->next != NULL && curr->next->data < newnode->data) {
      curr = curr->next;
    }
    newnode->next = curr->next;
    curr->next = newnode;
  }
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
    printf("Enter 6 -> SortedInsert\n");
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
        SortedInsert();
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
