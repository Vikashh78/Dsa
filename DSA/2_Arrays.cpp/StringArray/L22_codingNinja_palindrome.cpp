#include<iostream>
using namespace std;
#include<string>
#include<cctype>

int toLowerCase(char ch){
    if(ch>='a' && ch<='z' || ch >= 0 && ch <= 9)
    return ch;
    
    else{
        char temp = (ch -'A') + 'a';
        return temp;
    }
}


bool cheackPalindrome(const string& s){

    int i = 0, j = s.size()-1;
    while(i <= j){

        while(i < j && ! isalnum(s[i]))
        i++;

        while(i < j && ! isalnum(s[j]))
        j--;

        if(toLowerCase(s[i++]) != toLowerCase(s[j--]))
        return false;
    }

    return true;
}

int main(){

    // Case for only accepting alphabet and numeric charcaters-

    string s = {"c1o$d@eeDO1C"};
    
    if(cheackPalindrome(s)){
        cout<<"String is palindrome"<< endl;
    }
    else{
        cout<<"String is not palindrome"<<endl;
    }

    return 0;
}