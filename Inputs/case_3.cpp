// case 3: Here also size is not given and the inputs are like : {1, 2, 5, 9, 67} / [1 37 -13 90 7]

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    string s;
    getline(cin, s);
    
    if(s.front()=='{' && s.back()=='}' || s.front()=='[' && s.back()==']') { //catch
        s = s.substr(1, s.size()-2);
    }
    stringstream ss(s);
    vector<int> arr;
    string temp;

    while(getline(ss, temp, ',')) {
        arr.push_back(stoi(temp));
    }

    for(auto num: arr) cout<<num<<" ";


    return 0;
}