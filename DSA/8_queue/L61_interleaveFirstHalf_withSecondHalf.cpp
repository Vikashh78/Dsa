// you are given a queue with even lenght, rearrange the elements by interleaving the first half of the queue with second half
// of the queue.
// eg- input - [1 2 3 4], outut - [1 3 2 4]

#include <iostream>
using namespace std;
#include <queue>

void interleavedQueue(queue<int>& q) {
    // creating a new queue to store half element of the exixting queue
    queue<int> halfQ;
    int n = q.size()/2;

    for(int i=0; i<n; i++) {
        //putting half elemets of exixting queue to halfQ
        int temp = q.front();
        q.pop();

        halfQ.push(temp);
    }

    // pushing the altenate elements of halfQ along with q into the q itself
    while(! halfQ.empty()) {

        int x = halfQ.front();
        halfQ.pop();

        q.push(x);

        int y = q.front();
        q.pop();

        q.push(y);
    }
}

int main() {

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interleavedQueue(q);

    queue<int> que = q;

    while(! que.empty()) {
        cout<<que.front()<<" ";
        que.pop();
    }

    return 0;
}
