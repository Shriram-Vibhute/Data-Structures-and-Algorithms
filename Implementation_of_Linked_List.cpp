# include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    } // For creating a new node dynamically
};

void insertAtHead(Node* &Head, int data) {
    Node *temp = new Node(data);
    temp -> next = Head;
    Head = temp;
}

void insertAtTail(Node* &currentNode, int data) {
    Node *temp = new Node(data);
    currentNode -> next = temp;
    currentNode = temp;
}

void insertAtMiddle(int position, Node *&insertNode, Node *&head) {
    if(position == 0) {
        insertAtHead(head, insertNode->data);
        return;
    }
    Node *temp = head; // Securiong the head
    for(int i = 0; i < position - 1; i++) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        insertAtTail(temp, insertNode -> data);
        return;
    }
    insertNode -> next = temp -> next;
    temp -> next = insertNode;
}

void print(Node* &head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp->next;
    }
}

int main() {
    // Code for Head Insertion and Tail Insertion
    // Node *head = new Node(10);
    // Node *currentNode = head;
    // for(int i = 1; i <= 5; i++) {
    //     insertAtTail(currentNode, i);
    // }
    // print(head);

    // Code for Middle Insertion
    Node *head = new Node(10);
    Node *currentNode = head;
    insertAtTail(currentNode, 20);
    insertAtTail(currentNode, 40);
    insertAtTail(currentNode, 50);

    Node *insertNode = new Node(30);

    insertAtMiddle(4, insertNode, head);
    print(head);
    return 0;
}