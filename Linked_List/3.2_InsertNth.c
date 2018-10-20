// Write a function InsertNth() which can insert a new node at any index within a list.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void InsertNth() {

  if(head == NULL) {
    printf("\nError: Intially Linked_List is Empty\n\n");
    head = getnode();               // Intial Condition if List is Empty
    return;
  }
  NODE *curr = head;               // Will point to Current Element in Linked_List
  NODE *prev;                      // Will point to Previous Element in Linked_List
  int count = 0;                   // It will simply increase till the index value and help in adding the Element at that index
  int index;                       // Given Index
  printf("Enter the value of index for ith postion\n");
  scanf("%d", &index);

// To Find the Number of Nodes

  int num_nodes = 0;
  while(curr != NULL) {
    num_nodes++;                   // Finding the Number of Nodes in the Linked_List
    curr = curr->next;
  }
  curr = head;                     // Reintialize temp to head as it is at last postion Now

// Boundary Condition if index is last of the Linked_List

  if(index == num_nodes+1) {
    Insert_end();
    return;
  }

// Boundary Condition if Index is first of the Linked_List

  else if(index == 1) {
    Insert_front();
    return;
  }

// If index is not in Linked_List

  else if(index <=0 || index > num_nodes+1 ) {
    printf("\nError: Index not Exist\n");
    return;
  }

// To Insert at ith Postion if index is inbetween the list

  NODE *newnode;
  newnode = getnode();
  while(curr != NULL) {
    count++;                     // It will Increase till count = Index
    if(count == index) {
      prev->next = newnode;      // Here next of prev will point to new NODE
      prev = newnode;            // And making prev as newnode
      newnode->next = curr;      // and next of newnode will point to current
      return;
    }
    prev = curr;
    curr = curr->next;
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
    printf("Enter 6 -> InsertNth\n");
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
        InsertNth();
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
