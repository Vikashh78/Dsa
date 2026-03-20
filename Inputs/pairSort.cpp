//sort this: 2 3, 2 1, 4 6, 3 7

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;


int main() {
    string s;
    getline(cin, s);

    stringstream ss(s);
    vector<pair<int, int>> arr;
    string temp;

    while(getline(ss, temp, ',')) {
        stringstream ps(temp); //again stream
        int a, b;
        ps >>a >>b;
        arr.push_back({a, b});
    }

    // sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
    //     if(a.first != b.first)
    //         return a.first < b.first;
    //     else 
    //         return a.second < b.second;
    // });
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i].first <<" " <<arr[i].second;
        if(i != arr.size()-1) cout<<", ";
    }

    return 0;
}