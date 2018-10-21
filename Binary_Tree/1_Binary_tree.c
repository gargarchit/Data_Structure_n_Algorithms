// Implement Binary Search Tree

// Implement Insert node Function
// Implement Search node Function
// Implement preorder_display
// Implement postorder_display
// Implement inorder_display

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};
typedef struct Node NODE;

NODE *getnode(int x) {
  NODE *newnode = (NODE*)malloc(sizeof(NODE));
  newnode->data = x;
  newnode->left = newnode->right = NULL;
  return newnode;
}

// Function to insert in BST, return the Node
NODE *Insert(NODE *new, int x) {
  if(new == NULL) {  // Empty tree
    new = getnode(x);
    return new;
  }
  else if(x <= new->data) {
    new->left = Insert(new->left, x);
  }
  else if(x >= new->data) {
    new->right = Insert(new->right, x);
  }
  return new;
}

// Function to Search the Given Element in BST, return FOUND or NOTFOUND
void Search(NODE *new, int x) {
  if(new == NULL) {
    printf("\nNOT FOUND\n");
    return;
  }
  else if(new->data == x) {
    printf("\nFOUND\n");
    return;
  }
  else if(x <= new->data) {
    return Search(new->left, x);
  }
  else if(x >= new->data){
    return Search(new->right, x);
  }
  else {
    printf("\nNOT FOUND\n");
    return;
  }
}

void preorder_display(NODE *temp) {
  if(temp == NULL) {
    return;
  }
	else {
		printf(" %d ", temp->data);
		preorder_display(temp->left);
		preorder_display(temp->right);
	}
	return;
}
void postorder_display(NODE *temp) {
  if(temp == NULL) {
    return;
  }
  else {
    postorder_display(temp->left);
    postorder_display(temp->right);
    printf(" %d ", temp->data);
  }
return;
}
void inorder_display(NODE *temp) {
  if(temp == NULL) {
    return;
  }
  else {
    inorder_display(temp->left);
    printf(" %d ", temp->data);
    inorder_display(temp->right);
  }
  return;
}


void main() {
  int a;
	int ele;
	NODE *root = NULL;
	while(a!=0) {
		printf("\n1: To Insert Nodes");
		printf("\n2: Preorder Display Tree");
		printf("\n3: Postorder Display Tree");
		printf("\n4: Inorder Display Tree");
		printf("\n5: LookUp the Element");
		printf("\n0: Quit\n");
		scanf("%d", &a);
		if(a==0) {
			printf("-------------------------Thank You----------------------------\n");
			return;
		}
		switch(a) {
			case 1 :
			{
				printf("Enter the Data\n");
				scanf("%d", &ele);
        root = Insert(root, ele);
				break;
			}
			case 2 :
			{
				preorder_display(root);
				break;
			}
      case 3 :
      {
        postorder_display(root);
        break;
      }
      case 4 :
      {
        inorder_display(root);
        break;
      }
      case 5 :
      {
        printf("Enter the Data\n");
        scanf("%d", &ele);
        Search(root, ele);
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
