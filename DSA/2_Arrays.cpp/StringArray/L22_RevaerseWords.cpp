#include <iostream>
using namespace std;

void reverseWords(char s[]){
    int start = 0, end = '\0'-1;
    while(start <= end){
        swap(s[start++] , s[end--]);
    }
}

void print(char s[]){
    cout<<s;
}

int main(){

    char s[] = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    cout<<"Reverse is : ";
    reverseWords(s);
    print(s);

    return 0;
}