// You are provided with a arr[] of coins and a target, you have to take minimum no of coins to reach the target.
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

//Recursive apporaoch
int solveRec(vector<int> &coins, int target) {
    //base case
    if(target == 0) return 0;
    if(target < 0) return INT_MAX;

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int ans = solveRec(coins, target-coins[i]);
        if(ans != INT_MAX) {
            mini = min(mini, 1+ans);
        }
    }
    return mini;
}


int main() {

    vector<int> coins = {1,2,3};
    int n = coins.size();
    int target = 7;

    int ans = solveRec(coins, target);

    // vector<int> dp(n+1, -1);
    // int ans = solveMemo(coins, target, dp);

    if(ans == INT_MAX) {
        cout<<-1<<endl;
    } else {
        cout<<ans<<endl;
    }
    

    return 0;
}