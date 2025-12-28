#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;

//T: O(n square), S: O(N+E)
// also we can minimize T by using a minHeap to O(n logn)

class Graph {
    public:
    
    //create adjList
    unordered_map<int, list<pair<int, int>> > adjList;
    void addEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    //start the algo
    void primsMST(int n, vector<int> &key, vector<bool> &mst, vector<int> &parent) {
        //step 1.
        key[0] = 0;
        parent[0] = -1;

        for(int i=0; i<n; i++) {
            int mini = INT_MAX;
            int u;
            //find the minimum node
            for(int v=0; v<n; v++) {  //try to use min heap here
                if(mst[v] == false && key[v] < mini) {
                    u = v;
                    mini = key[v];
                }
            }

            //step 2. mark min node as true in mst
            mst[u] = true;

            //step 3. check its adjacent nodes
            for(auto neighbour : adjList[u]) {
               int v = neighbour.first;
               int w = neighbour.second;
               
               if(mst[v] == false && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
    }

};


int main() {

    Graph g;
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,3,8);
    g.addEdge(1,2,3);
    g.addEdge(1,4,5);
    g.addEdge(2,4,7);

    int n = 5;
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    g.primsMST(n, key, mst, parent);

    //now parent and key is ready
    cout<<"MST will be like this :"<<endl;
    int totalWight = 0;
    for(int i=0; i<n; i++) {
        totalWight+=key[i];
        cout<<"Node-> "<<i<<", parent-> " <<parent[i] <<", wight-> "<<key[i]<<endl;

    } cout<<endl;
    cout<<"Total weight of MST is : "<<totalWight <<endl;

    return 0;
}