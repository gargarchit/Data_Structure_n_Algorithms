#include <iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insert_front(Node* &head, int val){
    if(head == NULL){
        head = new Node(val);
        return;
    }

    Node* temp = new Node(val);
    temp->next = head;
    if(head != NULL) head->prev = temp;
    head = temp;
}

void insert_back(Node* &head, int val){
    if(head == NULL){
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newnode = new Node(val);
    temp->next = newnode;
    newnode->prev = temp;
}

int length_list(Node* head){
    int count = 0;
    while(head){
        count++;
        head = head->next;
    }
    return count;
}

void insertInMiddle(Node* &head, int val, int p){
    if(head == NULL or p == 0){
        insert_front(head, val);
        return;
    }
    else if(p >= length_list(head)){
        insert_back(head, val);
        return;
    }
    else {
        int cnt = 0;
        Node* temp = head;
        while(cnt<p-1){
            temp = temp->next;
            cnt++;
        }

        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
        return;
    }
    
}

void display(Node* head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = head;
    while(temp){
        cout << temp->data<< " -->";
        temp = temp->next;
    }
    cout << endl;
}

void display_rev(Node* head){
    if(head == NULL){
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    while(temp){
        cout << temp->data<< " -->";
        temp = temp->prev;
    }
    cout << endl;
}


Node* delete_head(Node* &head){
    if(head == NULL){
        cout << "Empty List" << endl;
        return NULL;
    }

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* temp = head->next;
    temp->prev = NULL;
    delete head;
    head = temp;
    return head;
}

Node* delete_tail(Node* &head){
    if(head == NULL){
        cout << "Empty List" << endl;
        return NULL;
    }

    if(head->next == NULL){
        delete head;
        return NULL;
    }

    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    temp->next->prev = NULL;
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* deletemiddle(Node* &head, int p){
    if(p == 0){
        delete_head(head);
        return head;
    }
    else if(p >= length_list(head)){
        head = delete_tail(head);
        return head;
    }
    else{
        int cnt = 0;
        Node* prev = NULL;
        Node* curr = head;
        while(cnt <= p-1)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        prev->next = curr->next;
        if(curr->next) curr->next->prev = prev;
        return head;
    }
}

int main(){
    Node* head = NULL;
    insert_front(head,2);
    insert_back(head,4);
    insert_back(head,6);
    insert_front(head,8);
    insert_back(head,10);
    insertInMiddle(head, 5,4);
    display(head);
    // head = delete_head(head);
    // head = delete_tail(head);
    head = deletemiddle(head, 4);
    display(head);
    display_rev(head);
    
}