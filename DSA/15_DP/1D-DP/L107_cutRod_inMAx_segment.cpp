// You are provided with a lenght of rod and the segments, you have to return the max segment possible to cut the given rod

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;


//Recursive solution
int solveRec(int n, vector<int> &segment) {
    //base case
    if(n == 0) 
        return 0;
    if(n < 0)
        return INT_MIN;

    int a = solveRec(n-segment[0], segment);
    int b = solveRec(n-segment[1], segment);
    int c = solveRec(n-segment[2], segment);

    if (a != INT_MIN) a += 1;
    if (b != INT_MIN) b += 1;
    if (c != INT_MIN) c += 1;

    int ans = max(a, max(b,c));
    return ans;
}


//Memoization 
int solveMemo(int n, vector<int> &dp, vector<int> &segment) {
    //base case
    if(n == 0) 
        return 0;
    if(n < 0) 
        return INT_MIN;

    //step.3
    if(dp[n] != -1)
        return dp[n];
    
    int a = solveMemo(n-segment[0], dp, segment);
    int b = solveMemo(n-segment[1], dp, segment);
    int c = solveMemo(n-segment[2], dp, segment);

    if (a != INT_MIN) a += 1;
    if (b != INT_MIN) b += 1;
    if (c != INT_MIN) c += 1;

    // step.2
    dp[n] = max(a, max(b,c));
    return dp[n];
}

//TODO: Tabulation -Bottom Up 


int main() {

    // int n=7, x=5, y=2, z=2;
    int n=7;
    vector<int> segment = {5,2,2};

    // int ans = solveRec(n, segment);
    // if(ans < 0) {
    //     cout<<-1<<endl;
    // } else {
    //     cout<<"Rod can be cut in "<<ans <<" segments";
    // }

    vector<int> dp(n+1, -1);
    int ans = solveMemo(n, dp, segment);
    if(ans < 0) {
        cout<<-1<<endl;
    } else {
        cout<<"Rod can be cut in "<<ans <<" segments";
    } 


    return 0;
}