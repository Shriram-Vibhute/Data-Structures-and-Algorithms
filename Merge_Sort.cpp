#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

Node *middle(Node *head) {
    Node *fast = head->next;
    Node *slow = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node *merge(Node *leftHead, Node *rightHead) {
    Node *firstHead = leftHead;
    Node *sceondHead = rightHead;

    Node *dummy = new Node(-1);
    Node *newHead = dummy;

    while (firstHead && sceondHead) {
        if(firstHead->data <= sceondHead->data) {
            dummy->next = firstHead;
            firstHead = firstHead->next;
        }
        else {
            dummy->next = sceondHead;
            sceondHead = sceondHead->next;
        }
        dummy = dummy->next;
    }

    if(firstHead) dummy->next = firstHead;
    else if(sceondHead) dummy->next = sceondHead;

    return newHead->next;
}

Node *mergeSort(Node *head) {
    if(head->next == nullptr) {
        return head;
    }

    Node *mid = middle(head);
    Node *leftHead = head;
    Node *rightHead = mid->next;
    mid->next = nullptr;

    // cout << leftHead->data << rightHead->data;

    Node *left = mergeSort(leftHead);
    Node *right = mergeSort(rightHead);

    // cout << left->data << ' ' << right->data << endl;

    Node* newHead = merge(left, right);
    return newHead;
}

int main() {
    Node *first = new Node(5);
    Node *second = new Node(4);
    first->next = second;
    Node *third= new Node(3);
    second->next = third;
    Node *forth = new Node(2);
    third->next = forth;
    Node *fifth = new Node(1);
    forth->next = fifth;

    Node *temp = mergeSort(first);
    
    while(temp) {
        cout << temp -> data << ' ';
        temp = temp->next;
    }
    return 0;
}