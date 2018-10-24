// Implement Binary Search Tree Write a Function To Insert a node

// To  traverse  the  tree  using  all  the  methods  i.e.,  inorder,  preorder  and postorder.

// Given  a  non-empty  binary  search  tree  (an  ordered  binary  tree),  return  the
// minimum data value found in that tree.

// Given a non-empty binary tree, count the number of leaf nodes in the tree.

// Given a non-empty binary tree, write a function to find the height of the tree.


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

// Preorder traversal
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

// Postorder traversal
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

//Minimum Data value
void Min(NODE *temp) {
  if(temp == NULL) {
    printf("\nTree is Empty\n");
    return;
  }
  while(temp->left != NULL) {
    temp = temp->left;
  }
  printf("Minimum Data Value in Tree; %d", temp->data);
  return;
}

// Height of Tree
int Height(NODE *temp) {
  if(temp == NULL) {
    return 0;
  }
  int LT = Height(temp->left);
  int RT = Height(temp->right);
  if(LT>RT) {
    return LT + 1;
  }
  else {
    return RT + 1;
  }
}

// Number of Leaf
int Num_leaf(NODE *temp) {
  if(temp == NULL) {
    return 0;
  }
  if(temp->left == NULL && temp->right == NULL) {
    return 1;
  }
  else {
    return Num_leaf(temp->left) + Num_leaf(temp->right);
  }
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
    printf("\n5: Minimum data Value");
    printf("\n6: Height of Tree");
    printf("\n7: Number of Leaf Node");
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
        Min(root);
        break;
      }
      case 6 :
      {
        int h;
        h = Height(root);
        printf("Height of Tree: %d", h);
        break;
      }
      case 7 :
      {
        int l;
        l = Num_leaf(root);
        printf("Number of leaf Node: %d", l);
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
