//case 2: if size is not given and inpts are space or comma sepearted

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


void spaceSeperated() {
    string s;
    getline(cin, s);
    stringstream obj(s);
    vector<int> arr;
    string temp;

    while(getline(obj, temp, ' ')) {
        arr.push_back(stoi(temp));
    }

    for(auto num: arr) cout<<num<<" ";
}

void commaSeperated() {
    string s;
    getline(cin, s);
    stringstream obj(s);
    vector<int> arr;
    string temp;

    while(getline(obj, temp, ',')) {
        arr.push_back(stoi(temp));
    }

    for(auto num: arr) cout<<num<<" ";
}

int main() {

    spaceSeperated();
    commaSeperated();

    return 0;
}