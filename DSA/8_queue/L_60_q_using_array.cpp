#include <iostream>
using namespace std;

//creating a class to implement the queue using array
class queue {

    //properties
    public:
    int size;
    int *arr;
    int front;
    int rear;

    //constructor
    queue(int s) {
        this->size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }



    //push function
    void enqueue(int x) {
        // queue is full
        if(rear == size) {
            cout<<"queue if full"<<endl;
        }
        else {
            arr[rear] = x;
            rear++;
        }
    }

    // pop function
    int dequeue() {
        //if q is empty
        if(front == rear) {
            return -1;
        }
        else {
           arr[front] = -1;
           front++;

           if(front == rear) { // start with zeroth index again
            front = 0;
            rear = 0;
           }
        }
    }

    //function for empty
    bool empty() {
        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }

    // function for front
    int Front() {
        if(front == rear) {
            return -1;
        }
        else {
            return arr[front];
        }
    }


    //function for size
    int Size() {
        if(front == rear) {
            return 0;
        }
        else {
            return (rear - front);
        }
    }

};

int main() {

    queue q(3);

    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(5);
    //q.enqueue(8);
    
    cout<<q.Front()<<endl;

    q.dequeue();
    cout<<q.Front()<<endl;


    // q.dequeue();
    // q.dequeue();
    // cout<<q.Front()<<endl;

    cout<<"size "<<q.Size()<<endl;;


    return 0;
}