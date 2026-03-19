// case 1- if n is given

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>> n;
    vector<int> arr(n);

    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }

    for(auto num : arr) {
        cout<<num<<" ";
    }

    return 0;
}