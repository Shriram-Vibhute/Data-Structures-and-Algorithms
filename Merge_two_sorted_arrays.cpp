#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr1[5] = {5, 6, 101, 150, 200};
    int arr2[4] = {1, 3, 9, 175};

    vector<int>array;
    int i = 0, j = 0;
    while(i < 5 && j < 4) {
        if(arr1[i] <= arr2[j]) {
            array.push_back(arr1[i]);
            i++;
        }
        else {
            array.push_back(arr2[j]);
            j++;
        }
    }

    while (i < 5) {
        array.push_back(arr1[i]);
        i++;
    }
    while(j < 4) {
        array.push_back(arr2[j]);
        j++;
    }
    for(auto it : array) {
        cout << it << ' ';
    }
    return 0;
}
