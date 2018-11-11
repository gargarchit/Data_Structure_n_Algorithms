// Circular Queue Basic Function C Library
#include"BST.h"
struct Qnode{
	struct node* item;
	struct Qnode *next;
};

typedef struct Qnode QNode;
QNode *last=NULL;

QNode* createNode(Node *item){
	QNode* newNode=(QNode*)malloc(sizeof(QNode));
	newNode->item=item;
	newNode->next=NULL;
	return newNode;
}


void enqueue(Node* item){
	QNode *newNode=createNode(item);
	if(last==NULL){
		last=newNode;
		last->next=newNode;
		return;
	}
	newNode->next=last->next;
	last->next=newNode;
	last=newNode;
}


Node* dequeue(){
	if(last==NULL){
		return NULL;
	}
	if(last->next==last){
		Node *item=last->item;
		free(last);
		last=NULL;
		return item;
	}
	Node* item;
	QNode *temp=last->next;
	last->next=(last->next)->next;
	item=temp->item;
	free(temp);
	return item;
}
