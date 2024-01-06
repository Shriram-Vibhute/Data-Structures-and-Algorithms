#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node *next;

        // Creation of node using constuctor
        node(int data) {
            this -> data = data;
            this ->next = NULL;
        }
};

// Read (Traverse the linked list)
void print(node *head) {
    while(head != NULL) {
        cout << head -> data << ' ';
        head = head -> next;
    }
    cout << endl;
}

// Update (Insertion of Linked List)
void insertAtHead(node *&head, node *&tail, int data) {
    node *newNode = new node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    // The head is passed by referance bcuz head is going to update
    node *temp = head;
    newNode -> next = temp;
    head = newNode;
}

void insertAtTail(node *&head, node *&tail, int data) {
    node *newNode = new node(data);
    if(head == NULL) {
        tail = newNode;
        return;
    } 

    node *temp = head;
    while(temp->next != NULL) {
        temp = temp -> next;
    }
    temp -> next = newNode;
    tail = newNode;
}

node *insertAtPosition(node *&head, node *&tail, int data, int position) {
    // Insertion at head
    if(position == 1) {
        insertAtHead(head, tail, data);
        return head;
    }
    node *temp = head;
    int counter = 0;
    while(counter < position - 2 && temp -> next != NULL) {
        counter++;
        temp = temp -> next;
    }
    // Insertion at Tail
    if(temp -> next == NULL) {
        insertAtTail(head, tail, data);
        return head;
    }
    else {
        // Insertion at intermediate position
        node *newNode = new node(data);
        newNode -> next = temp -> next;
        temp -> next = newNode;
        return head;
    }
}

// Deletion of Node

node *deleteNode(node *&head, node *&tail, int position) {
    node *temp = head;
    if(position == 1) {
        head = head->next;
        delete temp;
    }
    else {
        for(int i = 0; i < position - 2; i++) {
            temp = temp -> next;
        }
        if(temp->next == tail) {
            tail = temp;
            delete temp->next;
        } 
        node *dn = temp -> next;
        temp -> next = dn -> next;
        delete dn;       
    } // This
}

int main() {
    node *head = new node(1);
    node *tail = head;

    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5); 
    print(head);
    cout << head -> data << ' ' << tail -> data << endl;

    cout << "Insertion Start : " << endl;
    insertAtHead(head, tail, 100);
    cout << "New Head : " << head -> data << endl;
    insertAtPosition(head, tail, 5342, 4);
    print(head);
    insertAtPosition(head, tail, 9999, 1);
    cout << "New Head : " << head -> data << endl;
    insertAtPosition(head, tail, 1111, 9);
    cout << "New Tail : " << tail -> data << endl;
    print(head);

    // Deletion
    cout << "Deletion start : " << endl;
    deleteNode(head, tail, 2);
    print(head);
    deleteNode(head, tail, 1);
    print(head);
    deleteNode(head, tail, 7);
    print(head);
    cout << head->data << ' ' << tail->data;
    return 0;
}