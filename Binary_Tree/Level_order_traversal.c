#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"


void Level_order(Node *root){
	enqueue(root);
	Node *temp;
	while(temp=dequeue()){
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
		printf("%d ",temp->data);

	}
	printf("\n");
}

void inorder_display(Node *temp) {
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
	while(a!=0) {
		printf("\n1: To Insert Nodes");
		printf("\n2: Inorder Display Tree");
		printf("\n3: Level Order the Element");
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
          Insert(ele);
					break;
				}
      case  2:
        {
          inorder_display(root);
          break;
        }

      case 3 :
        {
          Level_order(root);
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
