#include<iostream>
#include<vector>
using namespace std;

vector<int> reverseArray(vector<int> arr){
    int start = arr.size()-6, end = arr.size()-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    return arr;
}

void printarray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    vector<int> arr;

    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(9);
    arr.push_back(1);

    cout<<"array before reverse : ";
    printarray(arr);
    cout<<"\n";
   
    cout<<"array after reversed is : ";
    vector<int> result = reverseArray(arr);
    printarray(result);

    return 0;
}
