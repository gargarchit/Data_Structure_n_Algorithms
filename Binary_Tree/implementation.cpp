#include <iostream>
using namespace std;

class Trees{
    public:
        int val;
        Trees* left;
        Trees* right;
        Trees(int val){
            this->val = val;
            left = NULL;
            right = NULL;
        }
};

void insert(Trees* &treenode, int val){

    if(treenode == NULL){
        treenode = new Trees(val);
    }
    
    else if(treenode->val > val){
        if(treenode->left!=NULL)
            insert(treenode->left, val);
        else
            treenode->left = new Trees(val);
    }
    else if(treenode->val < val){
        if(treenode->right!=NULL)
            insert(treenode->right, val);
        else
            treenode->right = new Trees(val);
    }
}

void inorder(Trees* treenode){
    if (treenode == NULL) 
        return; 

    inorder(treenode->left);
    cout << treenode->val << " ";
    inorder(treenode->right);
}

void preorder(Trees* treenode){
    if (treenode == NULL) 
        return; 

    cout << treenode->val << " ";
    preorder(treenode->left);
    preorder(treenode->right);
}

void postorder(Trees* treenode){
    if (treenode == NULL) 
        return; 

    postorder(treenode->left);
    postorder(treenode->right);
    cout << treenode->val << " ";
}


int sizeoftree(Trees* node){
    if(node == NULL) return 0;
    return sizeoftree(node->left) + 1 + sizeoftree(node->right);
}

int issame(Trees* node1, Trees* node2){
    if(node1 == NULL and node2 == NULL) return 1;
    if(node1 != NULL and node2 != NULL) 
        return (issame(node1->left, node2->left) and 
                node1->val == node2->val and 
                issame(node1->right, node2->right));

    return 0;
}



int main(){
    Trees* t = NULL;
    insert(t, 3);
    insert(t, 1);
    insert(t, 4);
    insert(t, 2);
    insert(t, 5);
    insert(t, 8);

    inorder(t);
    cout << endl;
    preorder(t);
    cout << endl;
    postorder(t);
    cout << endl;
    cout << "Size of Tree: " << sizeoftree(t)<< endl;

    Trees* tt = NULL;

    insert(tt, 3);
    insert(tt, 1);
    insert(tt, 4);
    insert(tt, 2);
    insert(tt, 5);
    insert(tt, 8);

    inorder(tt);
    cout << endl;

    if(issame(t, tt)) cout << "Same Trees"<<endl;
}