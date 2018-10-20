//Write a GetNth() function that takes a linked list and an integer index and returns the data value
//stored in the node at that index position.

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void GetNth() {
  if(head == NULL) {
    printf("\nError: Linked_List is Empty\n");
    return;
  }
  int count = 0;                   // It will simply increase till the index value and help in returning the value at that Index.
  NODE *temp = head;
  int index;                       // Given Index
  int num_nodes = 0;               // To Find the Number of Nodes 
  printf("Enter the Index to Find the data value at that NODE\n");
  scanf("%d", &index);
  while(temp != NULL) {
    num_nodes++;                   // Finding the Number of Nodes in the Linked_List
    temp = temp->next;
  }
  temp = head;                     // Reintialize temp to head as it is at last postion Now
  if(index > num_nodes || index <= 0) {  // Boundary Condition if Entered index is greater then Total number of nodes in Linked_List
    printf("\nError: Node at this Index doesn't Exits\n");   // or if 0 or less it will print Error Message
    return;
  }
  while(temp != NULL) {
    count++;
    if(index == count) {           // If count = index then it will print the data value at this index
      printf("\nThe Data Value at Index %d is |_%d_|\n", index, temp->data);
      return;
    }
    temp = temp->next;
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
    printf("Enter 6 -> To find the value at the given Index\n");
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
        GetNth();
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
