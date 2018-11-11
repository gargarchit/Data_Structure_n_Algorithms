struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node NODE;

NODE *newnode(int ele) {
	NODE *new = (NODE*)malloc(sizeof(NODE));
	new->data = ele;
	new->left = NULL;
	new->right = NULL;
	return new;
}

NODE *Insert(NODE *new, int ele) {
	if(new == NULL) {
		return newnode(ele);
	}
	if(ele < new->data ) {
		new->left = Insert(new->left, ele);
	}
	else if(ele > new->data) {
		new->right = Insert(new->right, ele);
	}
	return new;
}

NODE *FindMin(NODE *temp) {
	if(temp == NULL) {
		printf("\nEmpty Tree\n");
    return NULL;
	}
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

NODE *DeleteNode(NODE *temp, int ele) {
	if(temp == NULL) {
		printf("\nEmpty Tree\n");
		return temp;
	}
	if(ele < temp->data) {
		temp->left = DeleteNode(temp->left , ele);
	}
	else if(ele > temp->data) {
		temp->right = DeleteNode(temp->right, ele);
	}
	else {
    if(temp->left == NULL) {
  		NODE *temp1 = temp->right;
  		free(temp);
  		return temp1;
  	}
    if(temp->right == NULL) {
  		NODE *temp2 = temp->left;
  		free(temp);
  		return temp2;
  	}
    NODE *temp2 = FindMin(temp->right);
    temp->data = temp2->data;
    temp->right = DeleteNode(temp->right, temp2->data);
  }
	return temp;
}
