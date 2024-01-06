# include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;

        Node(int data) {
            this->data = data;
            this->next = nullptr;
            this->prev = nullptr;
        }

        Node(int data1, Node*prev1, Node*next1) {
            data = data1;
            prev = prev1;
            next = next1;
        }
};

void insertAtTail(Node *&prevNode, int data, Node *nextNode) {
    Node *newNode = new Node(data, prevNode, nextNode);
    prevNode->next = newNode; // Most Important Line
    prevNode = newNode;
}

void deleteHead(Node *&Head) {
    if(Head == NULL || Head -> next == NULL) {
        return ;
    }
    else {
        Node *nextHead = Head;
        Head = Head->next;
        Head -> prev = NULL;
        delete nextHead;
    }
}

void deleteTail(Node *&Head) {
    if(Head == NULL || Head -> next == NULL) {
        return ;
    }
    else {
        while (Head->next-> next != NULL)
        {
            Head = Head->next;
        }
        Node *delNode = Head->next;
        delNode->prev = NULL;
        Head->next = NULL;
        delete delNode; 
    }
}

int main() {
    vector<int>arr = {1, 2, 3, 4, 5};
    Node* Head = new Node(arr[0]);
    Node* temp = Head;
    Node* prevNode = Head;
    for (int i = 1; i < arr.size(); i++)
    {
        insertAtTail(prevNode, arr[i], nullptr);
    }
    // deleteHead(Head);
    // deleteTail(temp);
    while(Head != NULL) {
        cout << Head->data << ' ';
        Head = Head->next;
    }
}