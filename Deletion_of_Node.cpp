# include<iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;
    
    node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(node *&tail, int data) {
    node *temp = new node(data);
    tail -> next = temp;
    tail = tail -> next;
}

void print(node *&head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << ' ';
        temp = temp -> next;
    }
    cout << endl;
}

void deleteNode (node *&head, node *&tail, int position) {
    node *temp = head;
    if(position == 1) {
        head = head -> next;
        delete temp;
    }
    for(int i = 1; i < position - 1; i++) {
        temp = temp -> next;
    }
    node *dn = temp -> next;
    if(temp -> next -> next == NULL) {
        temp -> next = NULL;
        tail = temp;
        delete dn;
        return;
    }
    temp -> next = temp -> next -> next;
    delete dn;
}

int main() {
    node *head = new node(10);
    node *tail = head;
    for(int i = 1; i <= 4; i++) {
        insertAtTail(tail, (i*10 + 10));
    }
    deleteNode(head, tail, 1);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    return 0;
}