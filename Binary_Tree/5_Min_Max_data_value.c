#include <stdio.h>
#include <stdlib.h>

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

void FindMin(NODE *temp) {
	if(temp == NULL) {
		printf("\nEmpty Tree\n");
    return;
	}
	while(temp->left != NULL) {
		temp = temp->left;
	}
	printf("Minimum Value: %d", temp->data);
	return;
}

void FindMax(NODE *temp) {
  if(temp == NULL) {
    printf("\nEmpty Tree\n");
    return;
  }
  while(temp->right != NULL) {
    temp = temp->right;
  }
  printf("Maximum Value: %d", temp->data);
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
		printf("\n2: Inorder Display Tree");
		printf("\n3: Minimum Value");
		printf("\n4: Maximum Value");
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
          FindMin(root);
          break;
        }
      case 4 :
        {
          FindMax(root);
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
