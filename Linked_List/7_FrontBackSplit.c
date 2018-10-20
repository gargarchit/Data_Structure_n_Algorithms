// Given a list, split it into two sublists — one for the front half, and one for the back half. If
// the number of elements is odd, the extra element should go in the front list

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

void FrontBackSplit() {
  NODE *curr = head;               // Will point to Current Element in Linked_List

  // To Find the Number of Nodes
  int num_nodes = 0;
  while(curr != NULL) {
    num_nodes++;                   // Finding the Number of Nodes in the Linked_List
    curr = curr->next;
  }
  curr = head;                     // Reintialize temp to head as it is at last postion Now


  NODE *front;    // Help to print the Front list by pointing to last Node of front list
  NODE *back;     // Help to print the Back list by pointing to First Node of back list
  int i;

// If there are only 1 or 0 element in list then front will point to head and back to NULL
// as there will 0 element in back in this condition.

  if (num_nodes < 2) {
    front = head;
    back = NULL;
  }

// Here I set the front and back value

  else {
    int split = (num_nodes-1)/2;
    for(i = 0; i<split; i++) {
      curr = curr->next;
    }
    front = curr;      // Front will point to curr after it reaches split
    back = curr->next; // Back will point to next element of front
    front->next = NULL; // Breaking the List between front and back
  }

// Displaying Front List


  NODE *temp1 = head;     // help to Display front list.
  if(temp1 == NULL) {
    printf("\nFront and Back Lists are Empty\n");   // If this is Null then both list are Empty
    return;
  }
  printf("\nFront List: \n");
  while(temp1 != NULL) {
		printf("%d --> ", temp1->data);
		temp1 = temp1->next;
  }


  printf("\n----------------\n");

// Displaying Back list


  NODE *temp2 = back;
  if(temp2 == NULL) {
    printf("\nBack List is Empty\n");
    return;
  }
  printf("\nBack List: \n");
	while(temp2 != NULL) {
		printf("%d --> ", temp2->data);
		temp2 = temp2->next;
  }
  printf("\n");
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
    printf("Enter 6 -> FrontBackSplit()\n");
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
        FrontBackSplit();
        return;
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
