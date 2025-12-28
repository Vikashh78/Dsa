#include<iostream>
using namespace std;

// creating a character array and finding its length
int stringCount(char name[]){    //we don't need to pass size (parameter) here
    int i = 0, count = 0;
    while(name[i++] != '\0'){
        count++;
    }
    return count;
}

// **UpparCase -> lower Case-
char toLowerCase(char ch){
    if(ch > 'a' && ch <'z'){
        return ch;
    }

    else{
        char temp = (ch - 'A') + 'a';
        return temp;
    }
}

// **Lower case -> uppar case-
char toUpparCase(char ch){
    int temp = (ch - 'a') + 'A';
    return temp;
}

// *Character -> number-
int charToNum(char ch){
    int temp = (ch - 0);
    return temp;
}

int main(){
    
    char name[]={};

    cout<<"Enter your name : ";
    cin>> name;

    //name[3] = '\0';  //terminating string after third character

    cout<<"your name is : "<<name <<endl;

    int ans = stringCount(name);

    cout<<"Total number of character in your name is : "<<ans <<endl;




    char result = toLowerCase('V');
    cout<<"Upper case to lower case is : ";
    cout<<result <<endl;

    char res = toUpparCase('b');
    cout<<"Lower case to uppar case is  : "<<res <<endl;

    int value = charToNum('a');
    cout<<"Char to ASCII value is : "<<value <<endl;    
   

    return 0;
}