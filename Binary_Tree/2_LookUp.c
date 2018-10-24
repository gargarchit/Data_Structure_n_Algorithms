//Implement the LookUp () operation where given a binary search tree and a
// “target” value, searches the tree to see if it contains the target.

// Include Insert node Function
// Include Inorder Traversal Function



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


// Function to LookUp the Given Element in BST, return FOUND or NOTFOUND
void LookUp(NODE *new, int x) {
  if(new == NULL) {
    printf("\nNOT FOUND\n");
    return;
  }
  else if(new->data == x) {
    printf("\nFOUND\n");
    return;
  }
  else if(x <= new->data) {
    return LookUp(new->left, x);
  }
  else if(x >= new->data){
    return LookUp(new->right, x);
  }
  else {
    printf("\nNOT FOUND\n");
    return;
  }
}

// Inorder Traversal
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
		printf("\n2: Inorder Display Tree");
		printf("\n3: LookUp the Element");
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
        inorder_display(root);
        break;
      }
      case 3 :
      {
        printf("Enter the Data\n");
        scanf("%d", &ele);
        LookUp(root, ele);
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
