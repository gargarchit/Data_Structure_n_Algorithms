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

void Leaf_NonLeaf_Level(NODE* root,int level){
	if(root->left == NULL && root->right == NULL){
		printf("%d\tis at Leaf NODE\t\tLevel: %d\n",root->data,level);
		return;
	}
	printf("%d\tis at Non-leaf NODE\tLevel: %d\n",root->data,level);
	if(root->left)
		Leaf_NonLeaf_Level(root->left,level+1);
	if(root->right)
		Leaf_NonLeaf_Level(root->right,level+1);
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
		printf("\n3: Leaf_NonLeaf_Level");
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
          Leaf_NonLeaf_Level(root, 0);
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
