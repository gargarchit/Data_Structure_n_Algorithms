#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

void insert_front(Node* &head, int val){

    Node* n = new Node(val);
    Node* temp = head;
    n->next = head;
    if(temp!= NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
    }
    else{
        n->next = n;
    }
    head = n;
}

void display(Node* head){
    Node* temp = head;
    while(temp->next != head){
        cout << temp->data<< " -->";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

Node* getnode(Node* head, int data){
    Node* temp = head;
    while(temp->next!= head){
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }
    if(temp->data == data) return temp;
    return NULL;
}

void deleteNode(Node* &head, int data){
    Node* del = getnode(head, data);
    if(del == NULL){
        return;
    }

    if(head == del) {
        head = head->next;
    }
    
    Node* temp = head;
    while(temp->next!= del){
        temp = temp->next;
    }

    temp->next = del->next;

    delete del;
}

int main(){
    Node* head = NULL;
    insert_front(head,2);
    insert_front(head,3);
    insert_front(head,4);
    insert_front(head,8);
    display(head);
    deleteNode(head, 3);
    display(head);
    deleteNode(head, 4);
    display(head);
}