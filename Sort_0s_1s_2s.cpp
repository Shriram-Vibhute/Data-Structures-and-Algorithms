#include<bits/stdc++.h>
using namespace std;

void sort(vector<int> &array) {
    int size = array.size();
    int start = 0;
    int next = 0;
    int end = size - 1;

    while(next <= end) {
        if(array[next] == 0) {
            swap(array[start], array[next]);
            start++;
            next++;
        }
        else if(array[next] == 1) {
            next++;
        }
        else {
            swap(array[next], array[end]);
            end--;
        }
    }
}

int main() {
    vector<int>array(5);
    for(int i = 0; i < 5; i++) {
        cin >> array[i];
    }
    sort(array);
    for(auto it : array) {
        cout << it << ' ';
    }
    return 0;
}