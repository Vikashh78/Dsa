#include <iostream>
using namespace std;

class circularQueue {
    //properties
    public:
    int *arr;
    int size;
    int front;
    int rear;

    //constructor
    circularQueue(int s) {
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

    // enqueue function 
    void enqueue(int element) {
        //check if queue is full
        if((front == 0 && rear == size-1) || (front == rear +1)) {
            cout<<"queue is full"<<endl;
        }

        //queue is empty and pushing first element
        else if(front == -1 && rear == -1) { 
            front = rear = 0;
            arr[rear] = element;
        }

        //to maintain cyclic nature
        else if((rear == size-1) && (front != 0)) {
            rear = 0;
            arr[rear] = element;
        }

        //for normal flow
        else {
            rear++;
            arr[rear] = element;
        }
    }


    //-- four conditions to be checked
    // 1- if queue is empty
    // 2- to pop one element in empty queue
    // 3- maintain cyclic nature
    // 4- normal pop

    // dequeue function
    void dequeue() {
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


    //function for empty
    bool empty() {
        if(front == rear == -1) {
            return true;
        }
        else {
            return false;
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

    circularQueue q(3);

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(9);
    //q.enqueue(1);

    cout<<q.Front()<<endl;

    q.dequeue();
    q.dequeue();

    cout<<q.Front()<<endl;

    q.dequeue();
    q.dequeue();

    return 0;
}