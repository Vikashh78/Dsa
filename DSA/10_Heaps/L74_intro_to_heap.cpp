#include <iostream>
using namespace std;

// building a max heap
class heap {
    public:
    int arr[100];
    int size;

    //constructor
    heap() {
        arr[0] = -1;
        size = 0;
    }


    // function to insert element to heap     TC: O(logn)
    void insert(int val) {

        size = size +1;
        int index = size;
        arr[index] = val;

        while(index > 1) {

            int parent = index/2;

            if(arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            }

            else return;
        }
    }



    // function to delete element form heap       TC: O(logn)
    /*algo-
    1.always swap/replace last node with root node
    2.remove last node 
    3.propagate root node to its correct position */
    void deleteFromHeap() {

        if(size == 0) return;

        // step 1
        arr[1] = arr[size];

        // step 2
        size--;  

        //step 3
        int index = 1;
        while(index < size) {

            int leftIndex = 2*index;
            int rightIndex = 2*index+1;

            if(leftIndex < size  &&  arr[index] < arr[leftIndex]) {
                swap(arr[index], arr[leftIndex]);
                index = leftIndex;
            }
            else if(rightIndex < size  &&  arr[index] < arr[rightIndex]) {
                swap(arr[index], arr[rightIndex]);
                index = rightIndex;
            }
            else {
                return;
            }
        }
    }


    // function to print element
    void print() {
        for(int i=1; i<=size; i++) {
            cout<<arr[i] <<" ";
        }cout<<endl;
    }

};





// heapify function                            TC: O(logn)
void heapify(int arr[], int size, int i) {

    int largest = i;
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






int main() {

    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    h.deleteFromHeap();
    h.print();


    // building heap                         TC : O(n)
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int size = 5;
    for(int i=size/2; i>=1; i--) { // i=2 because we are excluding leaf nodes as they are already heapified (using- [n/2]+1 to n)
        heapify(arr, size, i);
    }

    cout<<"printing array after heapify\n";
    for(int i=1; i<=size; i++) {
        cout<< arr[i] <<" ";
    }cout<<endl;


    return 0;
}