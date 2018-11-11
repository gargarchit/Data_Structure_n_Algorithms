struct node{
	int data;
	struct node* left;
	struct node* right;

};

typedef struct node Node;
Node* root=NULL;

Node* createTreeNode(int data){
	Node* newNode=malloc(sizeof(Node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
void Insert(int data){
	Node *newNode=createTreeNode(data);
	if(root==NULL){
		root=newNode;
		return;
	}
	Node* temp=root;
	while(1){
		if(temp->data==data){
			printf("Cannot enter duplicate items in a BST\n");
			return;
		}

		else if(data<temp->data && temp->left!=NULL)
			temp=temp->left;

		else if(data>temp->data && temp->right!=NULL)
			temp=temp->right;

		else if(data<temp->data){
			temp->left=newNode;
			return;
		}

		else{
			temp->right=newNode;
			return;
		}
	}
}
