#include <iostream>
using namespace std;

// you are given a number you have to print its corresponding digit words

void printDigit(string arr[], int n){

    //base case-
    if(n == 0)
    return;
    
    //processing-
    int digit = n % 10;
    n = n / 10;

    //cout<<arr[digit]<<" ";   //print in reverse

    //recursive relation-
    printDigit(arr, n);

    cout<<arr[digit]<<" ";

}

int main(){

    int n;
    cout<<"Enter any number : ";
    cin>> n;

    //creating a map for digit to words
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    cout<<endl;
    printDigit(arr, n);
    cout<<endl;

    return 0;
}

