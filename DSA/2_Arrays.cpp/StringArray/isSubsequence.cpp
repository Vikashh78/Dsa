#include <iostream>
using namespace std;
#include <string>
#include <cstring>

//Thus, the overall time complexity of the program is : -> O(n⋅m)
//If you need a more efficient solution, consider using a two-pointer technique, 
//which has a time complexity of : -> O(n+m) .

 bool searchString(string t, char ch){

       for(int i=0; i<t.size(); i++){
            if(t[i] == ch){
                return  true;
            }
        }
        return false;
    }

bool isSubsequence(string s, string t) {
    
        int temp = 0;
        int count = 0;
        int i = 0, size = s.size();
        while(i < size){
            temp = s[i];
            if(searchString(t, temp)){
                count++;
                if(count == size){
                    return true;
                }
                i++;
            }
            else
            i++;
        }
        return false;
    }
    
int main(){

    //Test cases-
    string t = "ahbgdc";
    string s = "axc";
    
    if(isSubsequence(s,t)){
        cout<<endl;
        cout<<"["<< s <<"]" <<" is the subsequence of "<<"["<< t <<"]"<<endl;
        cout<<endl;
    }
    else{
        cout<<endl;
        cout<<"["<< s <<"]"<<" is the not subsequence of "<<"["<< t <<"]"<<endl;
        cout<<endl;
    }
    return 0;
}    