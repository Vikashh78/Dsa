#include <iostream>
#include <string>
using namespace std;

bool valid(char ch){
    if(ch >= 'a' && ch <='z' || ch >='A' && ch <= 'Z' || ch >= 0 && ch <= 9)
     return 1;

    return 0;
}

char toLower(char ch){
    if(ch >='a' && ch <= 'z' || ch >= 0 && ch <= 9)
    return ch;

    else{
        char temp = (ch - 'A') + 'a';
        return temp;
    }

}

bool checkPalindrome(string s){
    int i = 0, j = s.size()-1;
    while(i <= j){
        if((s[i++]) != (s[j--]))
        
        return 0;
    }
    return 1;
}

bool isPalindrome(string s){
    string temp;

    for(int i=0; i<s.size()-1; i++){
       if(valid(s[i]))
       temp.push_back(s[i]);
    }

    for(int i=0; i<s.size(); i++){
        temp[i]=toLower(temp[i]);
    }
    return checkPalindrome(temp);
}

int main(){

    string s = {"c1o$d@eeDO1C"};

    if(isPalindrome(s)){
        cout<<"Palindrome"<<endl;
    }

    else{
        cout<<"Not palindrome"<<endl;
    }

    return 0;
}