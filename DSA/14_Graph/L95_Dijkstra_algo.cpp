#include <iostream>
#include <unordered_map>
#include <set>
#include<vector>
#include <list>
#include <limits.h>
using namespace std;

// T: O(E log V), S: O(N+E)

class Graph {
    public:
    //create adjList
    unordered_map<int, list<pair<int, int>> > adjList;

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }


    void distance(vector<int> &dist, int src, set<pair<int, int>> &st) {

        dist[src] = 0; //initialization  ans vector 
        st.insert(make_pair(0, src));

        while(!st.empty()) {
            //fetch top value in set
            auto top = *(st.begin());

            int nodeDistance = top.first;
            int topNode = top.second;

            //remove top from set now
            st.erase(st.begin());

            //now traverse on neighbours
            for(auto neighbour : adjList[topNode]) {
                if(nodeDistance + neighbour.second < dist[neighbour.first]) {

                    //if true then remove prev entry for that node from set
                    auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                    if(record != st.end()) {
                        st.erase(record);
                    }

                    //now update distance
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    //now push this record into set
                    st.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
    }
};

int main() {

    Graph g;
    g.addEdge(0,1,7);
    g.addEdge(0,2,1);
    g.addEdge(0,3,2);
    g.addEdge(1,2,3);
    g.addEdge(1,3,5);
    g.addEdge(1,4,1);
    g.addEdge(4,3,7);
    
    int node = 5;
    int src = 0;

    vector<int> dist(5, INT_MAX);
    set<pair<int, int>> st;

    g.distance(dist, src, st);

    cout<<"Shortest path from "<<src <<"to every node is : ";
    for(int i=0; i<dist.size(); i++) {
        cout<<dist[i]<<" ";
    } cout<<endl;

    return 0;
}