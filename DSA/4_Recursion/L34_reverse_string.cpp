#include <iostream>
#include <string>
using namespace std;

// Pass by refernce-
void reverseString(string& s, int start, int end){

    //base case-
    if(start > end)
    return ;

    swap(s[start], s[end]);
    
    //recursive relation-
    reverseString(s, start+1, end-1);
    
}

int main(){

    string s = "data structure algorithm";

    reverseString(s, 0, s.size()-1);
    cout<<s <<endl;

    return 0;
}