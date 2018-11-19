//Implemenation of AVL Trees in C
// -- Archit

#include <stdio.h>
#include <stdlib.h>

struct AVLNode {
  struct AVLNode *left;
  struct AVLNode *right;
  int data;
  int height;
};
typedef struct AVLNode ANODE;

ANODE *getnode(int x) {
  ANODE *newnode = (ANODE*)malloc(sizeof(ANODE));
  newnode->data = x;
  newnode->height = 0;
  newnode->left = newnode->right = NULL;
  return newnode;
}

int max(int a, int b) {
  if(a > b) {
    return a;
  }
  else {
    return b;
  }
}

int height(ANODE *root) {
  if(!root) {
    return -1;
  }
  return root->height;
}

ANODE *singlerotateleft(ANODE *X) {
  ANODE *W = X->left;
  X->left = W->right;
  W->right = X;
  X->height = max(height(X->left), height(X->right))+1;
  W->height = max(height(W->left), X->height)+1;
  return W;
}

ANODE *singlerotateright(ANODE *X) {
  ANODE *W = X->right;
  X->right = W->left;
  W->left = X;
  X->height = max(height(X->left), height(X->right))+1;
  W->height = max(height(W->right), X->height)+1;
  return W;
}

ANODE *Doubleleft(ANODE *X) {
  X->left = singlerotateright(X->left);
  return singlerotateleft(X);
}

ANODE *Doubleright(ANODE *X) {
  X->right = singlerotateleft(X->right);
  return singlerotateright(X);
}

ANODE *Insert(ANODE *root,int x) {
  if(root == NULL) {  // Empty tree
    root = getnode(x);
    return root;
  }
  if(x < root->data) {
    root->left = Insert(root->left, x);
    if(height(root->left)-height(root->right) == 2) {
      if(x<root->left->data) {
        root = singlerotateleft(root);
      }
      else {
        root = Doubleleft(root);
      }
    }
  }
  if(x > root->data) {
    root->right = Insert(root->right,x);
    if(height(root->right)-height(root->left) == 2) {
      if(x<root->right->data) {
        root = singlerotateright(root);
      }
      else {
        root = Doubleright(root);
      }
    }
  }
  root->height = max(height(root->left), height(root->right)) + 1;
  return root;
}

void inorder_display(ANODE *temp) {
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
void main()
{
  int a;
  int ele;
  ANODE *root = NULL;
  while(a!=0) {
    printf("\n\n");
    printf("Enter 1 -> Insert Node in AVL\n");
    printf("Enter 2 -> Inorder\n");
    printf("Enter 0 -> Exit\n");
    scanf("%d", &a);
    if(a==0) {
      printf("-------------------------Thank You----------------------------\n");
      return;
    }
    switch(a) {
      case 1 :
      printf("Enter the Element to Insert\n");
      {
        scanf("%d", &ele);
        root = Insert(root, ele);
        break;
      }
      case 2 :
      {
        printf("inorder_display:\n");
        inorder_display(root);
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
