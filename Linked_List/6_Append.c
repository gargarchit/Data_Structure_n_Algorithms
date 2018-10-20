//Write an Append() function that takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
//and then sets 'b' to NULL.


#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE *getnode() {
	NODE *newnode;
	newnode  = (NODE*)malloc(sizeof(NODE));
	int ele;
	printf("Enter the Element in Linked List\n");
	scanf("%d", &ele);
	newnode->data = ele;
	newnode->next = NULL;
	return newnode;
}

void Insert_front(NODE **head) {
	NODE *newnode =	getnode();
	newnode->next = *head;
	*head = newnode;
}

void Insert_end(NODE **head) {

	NODE *newnode;
  newnode = getnode();
 	NODE *curr = *head;
	if(*head == NULL) {
		printf("\nError: Intially Linked_List is Empty\n\n");
		*head = newnode;
		return;
  }
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newnode;
	return;
}

void Delete_front(NODE **head) {
	if(*head == NULL) {
		return;
	}
	NODE *temp = *head;
	*head = temp->next;
	free(temp);
}

void Delete_end(NODE **head) {
	if(*head == NULL) {
		return;
	}
	NODE *curr = *head;
	NODE *prev;
	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	if(curr == *head) {
		*head = NULL;
	}
	else {
		prev->next = NULL;
	}
	free(curr);
}

void Display_LL(NODE **head) {
	if(*head == NULL) {
		printf("\nError: Linked_List is Empty\n");
	}
	NODE *temp = *head;
	while(temp != NULL) {
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
}


void Append(NODE **h1, NODE **h2) {
	NODE *curr;
	if(*h1 == NULL) {  // If first list is null directly append second to first
		*h1 = *h2;
		return;
	}
	else{
		curr = *h1;   // else tranverse till last of list 1 and append the list with next of last
		while(curr->next != NULL) {
			curr = curr->next;
		}          // say NULL to h2 and free its memory.
		curr->next = *h2;
		*h2 = NULL;
		free(*h2);
	}
}

void main() {
  int a;
	int b;
	NODE *head1 = NULL;
	NODE *head2 = NULL;
	while(a!=0) {
		printf("\nEnter 1: To create list 1\n");
		printf("\nEnter 2: To create list 2\n");
		scanf("%d", &b);
		printf("\n");
    printf("Enter 1 -> Insert_front in 1st list\n");
    printf("Enter 2 -> Delete_front in 1st list\n");
    printf("Enter 3 -> Insert_end in 1st list\n");
    printf("Enter 4 -> Delete_end in 1st list\n");
    printf("Enter 5 -> Display_LL in 1st list\n");
    printf("Enter 6 -> Append()\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    switch(a) {
      case 1 :
      {
				if(b==1) {
        Insert_front(&head1);
        Display_LL(&head1);
        break;
				}
				else if(b==2) {
					Insert_front(&head2);
	        Display_LL(&head2);
	        break;
				}
      }
      case 2 :
      {
				if(b==1) {
        Delete_front(&head1);
        Display_LL(&head1);
        break;
				}
				else if(b==2) {
					Delete_front(&head2);
	        Display_LL(&head2);
	        break;
				}
      }
      case 3 :
      {
				if(b==1) {
        Insert_end(&head1);
        Display_LL(&head1);
        break;
				}
				else if(b==2) {
					Insert_end(&head2);
	        Display_LL(&head2);
	        break;
				}
      }
      case 4 :
      {
				if(b==1) {
        Delete_end(&head1);
        Display_LL(&head1);
        break;
				}
				else if(b==2) {
					Delete_end(&head2);
					Display_LL(&head2);
	        break;
				}
      }
      case 5 :
      {
				printf("\nList 1 :\n");
        Display_LL(&head1);
				printf("\nList 2 :\n");
				Display_LL(&head2);
        break;
			}
			case 6 :
      {
        Append(&head1, &head2);
				printf("\nList 1 after appending:\n");
        Display_LL(&head1);
				printf("\nList 2 after appending:\n");
				Display_LL(&head2);
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
