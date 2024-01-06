#include<iostream>
using namespace std;

bool isEmpty(int size, int front, int real) {
    if(real != front) return false;
    else return true;
}

void push(int arr[], int size, int element, int front, int &real, int &count) {
    if(count == size) {
        cout << "Queue if Full" << endl;
    }
    else {
        arr[(real%size)] = element;
        count++;
        real++;
    }
}

void pop(int arr[], int size, int &front, int real, int &count) {
    if(isEmpty(size, front, real)) {
        cout << "Queue is Empty" << endl;
        return;
    }
    else {
        arr[(front%size)] = -1;
        front++;
        count--;
    }
}

void top(int arr[], int size, int front, int real) {
    if(isEmpty(size, front, real)) {
        cout << "Queue is Empty" << endl;
        return;
    }
    else cout << arr[(front%size)] << endl;
}

void print(int arr[], int size, int front, int real) {
    for(int i = front; i < real; i++) {
        cout << arr[i%size] << ' ';
    }
    cout << endl;
}

int main() {
    int arr[5];
    int size = 5;

    int front = 0;
    int real = 0;
    int count = 0;

    top(arr, size, front, real);
    pop(arr, size, front, real, count);

    push(arr, size, 1, front, real, count);
    push(arr, size, 2, front, real, count);
    push(arr, size, 3, front, real, count);
    push(arr, size, 4, front, real, count);

    push(arr, size, 5, front, real, count);
    print(arr, size, front, real);

    pop(arr, size, front, real, count);
    pop(arr, size, front, real, count);

    top(arr, size, front, real);

    print(arr, size, front, real);

    push(arr, size, 6, front, real, count);
    push(arr, size, 7, front, real, count);

    print(arr, size, front, real);

    return 0;
}