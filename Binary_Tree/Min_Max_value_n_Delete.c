#include <stdio.h>
#include <stdlib.h>
#include "Delete_Node.h"


int findMin(NODE *temp) {
	if(temp == NULL) {
		printf("\nEmpty Tree\n");
    return 0;
	}
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp->data;
}

void delMin(NODE *root){
	int min=findMin(root);
	root=DeleteNode(root,min);
}

int findMax(NODE *temp) {
  if(temp == NULL) {
    printf("\nEmpty Tree\n");
    return 0;
  }
  while(temp->right != NULL) {
    temp = temp->right;
  }
  return temp->data;
}

void delMax(NODE *root){
	int max=findMax(root);
	root=DeleteNode(root,max);
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
		printf("\n5: Delete Minimum Value");
		printf("\n6: Delete Maximum Value");
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
					int min = findMin(root);
					printf("\nMinimum Value: %d\n", min);
          break;
        }
      case 4 :
        {
					int max = findMax(root);
					printf("\nMaximum Value: %d\n", max);
          break;
        }
			case 5 :
        {
          delMin(root);
          break;
        }
      case 6 :
        {
        	delMax(root);
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
