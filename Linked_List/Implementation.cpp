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
    if(head == NULL){
        head = new Node(val);
        return;
    }

    Node* temp = new Node(val);
    temp->next = head;
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
    else if(p > length_list(head)){
        insert_back(head, val);
        return;
    }
    else {
        int cnt = 0;
        Node* temp = head;
        while(cnt<=p-1){
            temp = temp->next;
            cnt++;
        }

        Node* newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
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

void delete_head(Node* &head){
    if(head == NULL){
        cout << "Empty List" << endl;
        return;
    }

    Node* temp = head->next;
    delete head;
    head = temp;
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
        return head;
    }
}

// Linear Search
bool search(Node* head, int key){
    while(head){
        if(head->data == key){
            return true;
        }
        head = head->next;
    }
    return false;
}

bool search_recursively(Node* head, int key){
    if(head == NULL){
        return false;
    }
    if(head->data == key){
        return true;
    }
    else{
        return search_recursively(head->next, key);
    }
}

Node* take_input(){
    int d;
    cout << "Input number to add in linked list, write -1 to stop" << endl;
    cin >> d;
    Node* head = NULL;
    while(d!=-1){
        insert_front(head, d);
        cin >> d;
    }
    return head;
}

Node* take_input_fromfile(){
    int d;
    Node* head = NULL;
    while(cin >> d){
        insert_back(head, d);
    }
    return head;
}

// Operator Overloading
ostream& operator<<(ostream &os, Node* head){
    display(head);
    return os;
}

istream& operator>>(istream &is, Node* &head){
    head = take_input_fromfile();
    return is;
}

void reverse_ll(Node*&head){
    Node* temp = NULL;
    Node* curr = head;
    Node* nextp;
    while(curr){
        nextp = curr->next;
        curr->next = temp;
        temp = curr;
        curr = nextp;
    }
    head = temp;
}

Node* reverse_recursive(Node* &head){
    if(head->next == NULL or head == NULL){
        return head;
    }

    Node* shead = reverse_recursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return shead;
}

Node* midpoint(Node* &head){
    if(head == NULL or head->next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* kthNode_fromend(Node* &head, int k){
    if(head == NULL or head->next == NULL){
        return head;
    }
    if(k>length_list(head) or k<0){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    for(int i =0; i<k; i++){
        fast = fast->next;
    }
    while(fast){
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

Node* merge2sorted(Node* a, Node* b)
{
    if(a==NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    if(a == NULL and b == NULL){
        return NULL;
    }
    Node* mergelist = NULL;
    if(a->data < b->data){
        mergelist = a;
        mergelist->next = merge2sorted(a->next, b);
    }
    else{
        mergelist = b;
        mergelist->next = merge2sorted(a, b->next);
    }

    return mergelist;
}

// Merge sort
Node* mergesort(Node* head){
    // base
    if(head == NULL or head->next == NULL){
        return head;
    }

    // rec base
    // 1. break
    Node* mid = midpoint(head);
    Node* a = head;
    Node* b = mid->next;
    
    mid->next = NULL;
    // rec sort
    a = mergesort(a);
    b = mergesort(b);

    // merge
    Node* c = merge2sorted(a,b);
    return c;
}

int main(){
    // Node* head = take_input_fromfile();
    Node* head;
    // Node* head2 = NULL;
    // insert_back(head2,2);
    // insert_back(head2,4);
    // insert_back(head2,6);
    // insert_back(head2,8);
    // insert_back(head2,10);
    cin >> head;
    cout << head;
    head = mergesort(head);
    cout << head;
    // cout << head2;
    // Node* mergelist = merge2sorted(head, head2);
    // cout << mergelist;

    // head = reverse_recursive(head);
    // reverse_ll(head);
    // cout << head;
    // Node* mid = midpoint(head);
    // cout << mid;
    // Node* kthnodefromend = kthNode_fromend(head, 1);
    // cout << kthnodefromend;
    // display(head);
    // delete_head(head);
    // display(head);
    // head = delete_tail(head);
    // head = deletemiddle(head, 2);
    // display(head);
    // if(search(head, 7)){
    //     cout << "Present" << endl;
    // } else{
    //     cout << "Absent" << endl;
    // }

    // if(search_recursively(head, 5)){
    //     cout << "Present" << endl;
    // } else{
    //     cout << "Absent" << endl;
    // }
}