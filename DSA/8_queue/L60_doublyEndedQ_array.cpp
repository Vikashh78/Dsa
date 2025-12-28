#include <iostream>
using namespace std;

class deque {
    public:
    //properties
    int *arr;
    int size;
    int front;
    int rear; 

    deque(int s) {
        this->size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    //-- four conditions to be checked
    // 1- if queue is full
    // 2- to push one element in empty queue
    // 3- maintain cyclic nature
    // 4- normal push

    void enQueue_front(int x) {
        //if queue is full
        if((front == 0 && rear == size-1) || (front == rear +1)) {
            cout<<"queue is full"<<endl;
        }

        // if only one element to push
        else if(front == -1 && rear == -1) {
            front = rear = 0;
            arr[front] = x;
        }

        // maintain circular nature
        else if(front == 0 && rear != size-1) {
            front = size-1;
            arr[front] = x;
        }
        // normal push
        else {
            front--;
            arr[front] = x;
        }
    }


    void enQueue_back(int x) {
         //check if queue is full
         if((front == 0 && rear == size-1) || (front == rear +1)) {
            cout<<"queue is full"<<endl;
        }

        //queue is empty and pushing first element
        else if(front == -1 && rear == -1) { 
            front = rear = 0;

        }

        //to maintain cyclic nature
        else if((rear == size-1) && (front != 0)) {
            rear = 0;
            
        }

        //for normal flow
        else {
            rear++;
        }

        arr[rear] = x;
    }




    //-- four conditions to be checked
    // 1- if queue is empty
    // 2- to pop one element in empty queue
    // 3- maintain cyclic nature
    // 4- normal pop

    void deQueue_front() {
        // queue is empty
        if(front == -1) {
            cout<<"queue is empty"<<endl;
        }

        // if single element is present
        else if(front == rear) {
            front = rear = -1;
        }

        // to maintain cyclic nature
        else if(front == size-1) { 
            front = 0;
        }

        // normal pop
        else {
            front++;
        }
    }


    void deQueue_back() {
        // queue is empty
        if(front == -1) {
            cout<<"queue is empty"<<endl;
        }

        // if single element is present
        else if(front == rear) {
            front = rear = -1;
        }
        
        // maintain cyclic nature
        else if(rear == 0) {
            rear = size-1;
        }

        // normal pop
        else {
            rear--;
        }
    }

    // function for front
    int Front() {
        if(front == -1) {
            return -1;
        }
        else {
            return arr[front];
        }
    }

};


int main() {

    deque q(4);

    q.enQueue_front(1);
    cout<<q.Front()<<endl;

    q.enQueue_front(4);
    cout<<q.Front()<<endl;

    q.deQueue_back();
    cout<<q.Front()<<endl;

    

    return 0;
}