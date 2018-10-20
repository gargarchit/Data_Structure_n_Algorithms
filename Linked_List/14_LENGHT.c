// Write a function LENGTH(X) to count the number of nodes in a singly linked list P, where P
// points to the first node in the list. The last node has link field NULL.


#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"

int LENGHT() {
  NODE *curr = head;               // Will point to Current Element in Linked_List

  // To Find the Number of Nodes
  int num_nodes = 0;
  while(curr != NULL) {
    num_nodes++;                   // Finding the Number of Nodes in the Linked_List
    curr = curr->next;
  }
  return num_nodes;
}



int main() {
  int a;
  while(a!=0) {
    printf("\n\n");
    printf("Enter 1 -> Insert_front\n");
    printf("Enter 2 -> Delete_front\n");
    printf("Enter 3 -> Insert_end\n");
    printf("Enter 4 -> Delete_end\n");
    printf("Enter 5 -> Display_LL\n");
    printf("Enter 6 -> LENGHT()\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    if(a==0) {
      printf("-------------------------Thank You----------------------------\n");
      return 0;
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
        int len = LENGHT();
        printf("\nNumber of Nodes in this List: %d\n", len);
        return 0;
      }
      default :
      {
        printf("Wrong Value Detacted\n");
        break;
      }
      return 0;
    }
  }
}
