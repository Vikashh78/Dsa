#include <iostream>
using namespace std;
#include <vector>

// comlexity : TC-O(N!),  SC- O(N*N)

void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
	// this function simply copying the curr element postions from bard to ans

	vector<int> temp;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}



bool isSafe(int row, int col, vector<vector<int>>& board, int n) {
	/*Note--
	 we will not check for :
	 1. up and down col
	 2. for right same row
	 3. right side diagonals 
	*/

	// check foe same row (left side)
	int r = row;
	int c = col; 

	while(c >= 0) {
		if(board[r][c] == 1){
			return false;
		}
		c--;
	}

	//check for left diagonals
	// 1.left up diagonal
	r = row;
	c = col;
	while(r>=0 && c>=0) {
		if(board[r][c] == 1){
			return false;
		}
		r--;
		c--;
	}

	// 2. for down left diagonal
	r = row;
	c = col;
	while(r<n && c>=0) {
		if(board[r][c] == 1) {
			return false;
		}
		r++;
		c--;
	}

	return true;  // everthing is ok


    // can you optimize the searching complexity from O(n) -> O(1) ?
}



void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {

	//base case
	if(col == n) {
		addSolution(ans, board, n); 
		return;
	}

	//solve only one case rest recursion will handle
	for(int row=0; row<n; row++) {

		if(isSafe(row, col, board, n)) {

			board[row][col] = 1;
			
			solve(col+1, board, ans, n);  // make recursive call for next col

			board[row][col] = 0;   // while backtracking
		}
	}
}



int main() {

    //size of board is n=4
    int size = 4;

    vector<vector<int>> board(size, vector<int>(size, 0));  // all position are initialized with zero

	vector<vector<int>> ans;  //this ans vector will contain more than one solution

	int col = 0;
	solve(col, board, ans, size);

    
    cout<<"Possible postions of queen in board are - \n";
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    } 
    cout<<endl;


    return 0;
}