#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main()
{
    vector<int>arr = {2, 3};
    Node *n = new Node(arr[0]);
    cout << n->data << endl;
    cout << n->next << endl;

    return 0;
}