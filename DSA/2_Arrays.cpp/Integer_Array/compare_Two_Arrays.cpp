// You are given string and two arrays lower[] and upper[] with initially elements 0
// if first element of string is of lower case then mark 1 in lower[] and if it is of 
// upper case then mark 1 in upper[] ans so on.... also compare those two arrays if equal then return
// true else return false

#include <iostream>
using namespace std;
#include <vector>
#define MAX 26    // macro

bool isNice(vector<int>& lower, vector<int>& upper){
    for(int i=0; i<MAX; i++){
        if(lower[i] != upper[i])
            return false;
    }
    return true;
}

int main() {

    vector<int> upper (MAX, 0);
    vector<int> lower (MAX, 0);

    string str = "YaaBO_.!y,AboA";

    for(char ch : str){
        if(ch >= 'a' && ch <= 'z'){
            lower[ch] = 1;
        }
        else if(ch >='A' && ch <='Z'){
            upper[ch] = 1;
        }
    }


    bool result = isNice(lower, upper);

    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }

    return 0;
}