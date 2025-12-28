#include <iostream>
using namespace std;



void heapify(int arr[], int size, int i) {

    int largest = i;       // 1 based indexing
    int left = 2*largest;
    int right = 2*largest+1;

    if(left <= size  &&  arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= size  &&  arr[largest] < arr[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[i], arr[largest]);
        // check correct position for further elements
        heapify(arr, size, largest); 
    }
}

// heap sort                         TC: O(nlogn)
void heapSort(int arr[], int n) {

    int size = n;
    
    while(size > 1) {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}



int main() {

    int arr[6] = {-1, 54, 53, 55, 52, 50};  // 1 based index
    int size = 5;


    // build heap
    for(int i=size/2; i>0; i--) { // i=2 because we are excluding leaf nodes as they are already heapified (using- [n/2]+1 to n)
        heapify(arr, size, i);
    }

    heapSort(arr, size);

    cout<<"printing array after sorting\n";
    for(int i=1; i<=size; i++) {
        cout<< arr[i] <<" ";
    }cout<<endl;

    return 0;
}