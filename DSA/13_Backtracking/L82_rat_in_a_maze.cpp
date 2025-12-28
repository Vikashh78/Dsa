#include <iostream>
using namespace std;
#include <vector>



// check if the moves are possible or not
bool isSafe(int newX, int newY, vector<vector<bool>>& visited, vector<vector<int>>& arr, int n) {

    if((newX >= 0 && newX < n) && (newY >= 0 && newY < n) && (visited[newX][newY] == 0) && (arr[newX][newY] == 1)) {
        return true;
    }

    return false;
}


void solve(int x, int y, vector<vector<int>>& arr, int n, vector<string>& ans, vector<vector<bool>>& visited, string path) {
    
    //base case
    if(x == n-1  &&  y == n-1) {
        ans.push_back(path);
        return;
    }

    // four moves- D,L,R,U
    visited[x][y] = 1;

    // 1.down
    if(isSafe(x+1, y, visited, arr, n)) {
        //recursive call
        solve(x+1, y, arr, n, ans, visited, path +'D');
    }

    // 1.left
    if(isSafe(x, y-1, visited, arr, n)) {
        //recursive call
        solve(x, y-1, arr, n, ans, visited, path +'L');
    }

    // 1.right
    if(isSafe(x, y+1, visited, arr, n)) {
        //recursive call
        solve(x, y+1, arr, n, ans, visited, path +'R');
    }

    // 1.up
    if(isSafe(x-1, y, visited, arr, n)) {
        //recursive call
        solve(x-1, y, arr, n, ans, visited, path +'U');
    }

    // while returning mark visited = 0
    visited[x][y] = 0;
}





int main() {

    //input array
    vector<vector<int> > arr = {
                                {1,0,0,0},
                                {1,1,0,0},
                                {1,1,0,0},
                                {0,1,1,1}
    };
    int row = arr.size();
    int col = arr[0].size();
    int n = 4;

   
    // each row is a vector<bool> of size col, initialized to false
    vector<vector<bool> > visited (row, vector<bool> (col, 0));
    vector<string> ans;
    string path = "";

    if(arr[0][0] == 0) {
        return 0;
    }

    solve(0, 0, arr, n, ans, visited, path);

    cout<<"possible paths are : ";
    for(auto i : ans) {
        cout << i <<" ";
    }
    cout<<endl;



    return 0;
}