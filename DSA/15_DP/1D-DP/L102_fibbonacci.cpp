#include <iostream>
#include <vector>
using namespace std;

//Method 1 Top Down: Memoization and Recursion, T-O(n) and S-O(n)+O(n) 
int fib(int n, vector<int> &dpArr) {
    //Base case
    if(n <= 1) return n;

    //step 3.
    if(dpArr[n] != -1) 
    return dpArr[n];

    //step 2.
    dpArr[n] = fib(n-1, dpArr) + fib(n-2, dpArr);
    return dpArr[n];
}

//Method 2 (Bottom-Up : Tabulation)  T and S : O(n)
int fib(int n) {

    if (n == 0) return 0;
    if (n == 1) return 1;

    //step 1.
    vector<int> dp(n+1);

    // step 2.
    dp[0] = 0, dp[1] = 1;

    // step 3.
    for(int i=2; i<=dp.size(); i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

//3rd approach - space optimization i,e : O(1)
int fibb(int n) {

    int prev1 = 1;
    int prev2 = 0;

    if(n == 0) return 0;

    for(int i=2; i<=n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    cout<<"Enter the nth series to get ans : ";
    int n;
    cin >> n;

    //step 1
    vector<int> dpArr(n+1, -1);

    // cout << fib(n, dpArr) <<endl;

    // cout<< fib(n) <<endl;

    cout<< fibb(n) <<endl;

    return 0;
}