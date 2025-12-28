#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1, 1e8); //1e9 - infinity
    dist[src] = 0;

    //run for n-1 times the formuls
    for(int i=1; i<n; i++) {
        //traverse on each edge
        for(int j=0; j<m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e8 && ((dist[u] + wt) < dist[v]) ) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // return dist;

    // check for -ve weight cycle
    //run the formula for one more time

    bool cycle = 0;
    for(int j=0; j<m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e8 && ((dist[u] + wt) < dist[v]) ) {
            dist[v] = dist[u] + wt;
            cycle = 1;
        }
    }
    if(cycle == 0) ; //shortest path present
        return vector<int>(dist.begin()+1, dist.end()); //for 1 based indexing

    return {-1}; // -ve weight cycle is present in graph
    
}

int main() {

    int nodes, edgesCount, src;
    cin >> nodes >> edgesCount >> src;

    vector<vector<int>> edges;  // each edge = {u, v, wt}
    for (int i = 0; i < edgesCount; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    vector<int> ans = bellmonFord(nodes, edgesCount, src, edges);
    
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;

    return 0;
}