// case 1- if n is given

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
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

    

    // for string

    // 3
    // apple
    // banana
    // mango


    int x;
    cin >> x;
    cin.ignore();

    vector<string> input(x);

    for(int i = 0; i < x; i++) {
        getline(cin, input[i]);
    }

    return 0;

}