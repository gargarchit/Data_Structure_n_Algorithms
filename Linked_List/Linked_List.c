


struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE *getnode() {
	NODE *newnode;
	newnode  = (NODE*)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("there is no more space in the system");
		return;
	}
	int ele;
	printf("Enter the Element in Linked List\n");
	scanf("%d", &ele);
	newnode->data = ele;
	newnode->next = NULL;
	return newnode;
}

NODE *head = NULL;

void Insert_front() {
	NODE *newnode =	getnode();
	newnode->next = head;
	head = newnode;
}

void Insert_end() {

	NODE *newnode;
        newnode = getnode();
 	NODE *curr = head;
	if(head == NULL) {
                printf("\nError: Intially Linked_List is Empty\n\n");
                head = newnode;
		return;
        }
	while(curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newnode;
	return;
}

void Delete_front() {
        if(head == NULL) {
                return;
        }
	NODE *temp = head;
	head = head->next;
	free(temp);
}

void Delete_end() {
	if(head == NULL) {
		return;
	}
	NODE *curr = head;
	NODE *prev;
	while(curr->next != NULL) {
		prev = curr;
		curr = curr->next;
	}
	if(curr == head) {
		head = NULL;
	}
	else {
		prev->next = NULL;
	}
	free(curr);
}

void Display_LL() {
	if(head == NULL) {
                printf("\nError: Linked_List is Empty\n");
        }
	NODE *temp = head;
	while(temp != NULL) {
		printf("%d --> ", temp->data);
		temp = temp->next;
	}
}
