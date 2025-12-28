#include <iostream>
using namespace std;
#include <vector>

void print(vector<int> arr, int key){

    cout<<"Element is "<< key<<": ";
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

bool linearSearch(vector<int> arr, int key){

    //printing each function call to see the flow of code-
    print(arr, key);

    //base case-
    if(arr.size() == 0)
    return false;

    if(arr[0] == key){
        return true;
    }
    
    return linearSearch(vector<int> ( arr.begin()+1,  arr.end() ),  key);

}

int main(){

    vector<int> arr = {2,8,66,4,3,7,20};

    int key = 7;

    bool res = linearSearch(arr, key);

    if(res){
        cout<<"Element found "<<endl;
    }
    else{
        cout<<"Element not found "<<endl;
    }

    return 0;
}