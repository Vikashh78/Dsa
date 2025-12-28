#include<iostream>
using namespace std;
#include <unordered_map>
#include<queue>
#include<set>
#include<vector>

// T/S : O(N+E)

void createAdjList(unordered_map<int, set<int>> &adjList, vector<vector<int>> &edges) {
   
   for(int i=0; i<edges.size(); i++) {
      int u = edges[i][0];
      int v = edges[i][1];

      adjList[u].insert(v);
      adjList[v].insert(u);
   }
}


void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {

   queue<int> q;
   q.push(node);
   visited[node] = true;

   while(! q.empty()) {
      int frontNode = q.front();
      q.pop();

      // store front node into ans
      ans.push_back(frontNode);

      //traverse all the neighbours of frontNode
      for(auto neighbours : adjList[frontNode]) {
         if(! visited[neighbours]) {
            q.push(neighbours);
            visited[neighbours] = true;
         }
      }
   }
}



int main() {

   int n = 5;
    
   vector<vector<int>> adjVector = {
      {0,1},
      {0,4},
      {1,2},
      {4,3},
      {2,3}
   };

   //data structures we need
   unordered_map<int, set<int>> adjList;
   vector<int> ans;
   unordered_map<int, bool> visited;

   createAdjList(adjList, adjVector);

   for(auto &pair : adjList) { // loop to traverse all component of graph
      int node = pair.first;
      if(! visited[node]) {
         bfs(adjList, visited, ans, node);
      }
   }


   // output
   for (auto node : ans) {
      cout << node << " ";
   }
   cout << endl;   


   return 0;
}