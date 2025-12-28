#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
template <typename T>   

//implementing directed and undirected graph
class graph {

    public:
        unordered_map<T, list<T>> adj; //generic from

        void addEdge(int u, int v, bool direction) {   // O(1)
            //direction = 0 : undirected graph
            //direction = 1 : directed graph

            /*
            This adds an edge from u to v.
            1.Look up node u in the adjacency list.
            2.If u is not present, create an empty vector :- adj[u] = vector<int>();
            3.Add v to the vector (i.e., register that v is a neighbor of u). 
            */
            adj[u].push_back(v);
            // u-starting node (or source), v-destination node (or neighbor)

            if(direction == 0) {
                // v-starting node (or source), u-destination node (or neighbor)
                adj[v].push_back(u);
            }
        }
                
       
        void printAdjLIst() {     // O(N+E)
            for(auto i : adj) {
                cout<< i.first << "-> ";
                for(auto j : i.second) {
                    cout<< j <<", ";
                }
                cout <<endl;
            }
        }  
};



int main() {

    int nodes;
    cout<<"Enter the number of nodes" <<endl;
    cin>>nodes;

    int edges;
    cout<<"Enter the number of edges" <<endl;
    cin>>edges;

    graph<int> g;

    // always length of i will be equal to edge
    cout<<"Enter relation b/w nodes and edges" <<endl;
    for(int i=0; i<edges; i++) {
        int u, v;
        cin>>u >>v;
        g.addEdge(u, v, 0);
    }
    
    g.printAdjLIst();
}

/*  0 1   ye sabhi input jaa rhe hai (u,v) ke form me
    0 4
    1 2
    2 3
    1 3
    4 3
*/