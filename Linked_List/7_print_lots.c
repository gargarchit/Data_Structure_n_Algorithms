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

// Here if P data is count then print l->data and update P and L to next
// Otherwise only Update L to next
void print_lots(NODE **h1, NODE **h2) {
  NODE *L = *h1;
  NODE *P = *h2;
  int count = 1;
  while(L != NULL && P != NULL) {
    if(P->data == count) {
      printf("%d  ", L->data);
      P = P->next;
    }
    L = L->next;
    count++;
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
    printf("Enter 6 -> Print_lots()\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    if(a==0) {
      printf("-------------------------Thank You----------------------------\n");
      return;
    }
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
        print_lots(&head1, &head2);
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
