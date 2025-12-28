#include<iostream>
using namespace std;

char toLowerCase(char ch){
    if(ch >= 'a' && ch <='z'){
        return ch;
    }

    else{
        char temp = (ch - 'A') + 'a';
        return temp;
    }
}

bool isPalindrome(char arr[], int size){
    
    int i=0, j=size-1;   
    while(i <= j){
        
        // Lowercase function is called here
        if(toLowerCase(arr[i++]) != toLowerCase(arr[j--])){
            return false;
        }
    }
    return true;
}

int main(){

    int size;
    cout<<"Enter size : ";
    cin>>size;

    char arr[size]={};
    cout<<"Enter characters : ";
    cin>>arr;

    if(isPalindrome(arr, size)){
        cout<<"Character is palindrome"<<endl;
    }
    else{
        cout<<"Character is not palindrome"<<endl;
    }


    return 0;
}