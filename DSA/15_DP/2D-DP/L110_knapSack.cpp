#include <iostream>
#include <vector>
using namespace std;
//whenever two paramaters will be change in function then it is called 2D Dp.


//Recursive method : byfinding subset of the weight array, O(exponential) 
int solveRec(vector<int> &weight, vector<int> &value, int index, int capacity) {
    //base case : just suppose only one item to steal, then compare its wight with knapsack capacity
    if(index == 0) {
        if(weight[0] <= capacity)
            return value[0];
        else 
            return 0;
    }

    int incl = 0, excl = 0;
    if(weight[index] <= capacity)
        incl = value[index] + solveRec(weight, value, index-1, capacity-weight[index]);
    
    excl = 0 + solveRec(weight, value, index-1, capacity);

    return max(incl, excl);
    
}


//Top-dwn Rec+Memo : O(N*W), O(N*W)
int solveMemo(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp) {

    if(index == 0) {
        if(weight[0] <= capacity)
            return value[0];
        else 
            return 0;
    }
    
    if(dp[index][capacity] != -1) 
        return dp[index][capacity];
        

    int incl = 0, excl = 0;
    if(weight[index] <= capacity)
        incl = value[index] + solveRec(weight, value, index-1, capacity-weight[index]);
    
    excl = 0 + solveRec(weight, value, index-1, capacity);

    dp[index][capacity] = max(incl, excl);
    
    return dp[index][capacity];
}




//Tabulation : Bottom-up : O(N*W), O(N*W)
int solveTabu(vector<int> &weight, vector<int> &value, int n, int capacity) {
    //step.1
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    //step.2 -- base case analysis
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    //step.3
    for(int index=1; index<n; index++) {
        for(int w=0; w<=capacity; w++) {
            int include = 0;

            if(weight[index] <= w)
                include = value[index] + dp[index-1][w-weight[index]];
            
            int exclude = 0 + dp[index-1][w];

            dp[index][w] = max(include, exclude);
        }
    } 
    return dp[n-1][capacity]; 
}


//Space optimization O(N*W), O(W)+O(w)
int solveOptm(vector<int> &weight, vector<int> &value, int n, int capacity) {
    //step.1
    vector<int> prev(capacity+1, 0);
    vector<int> curr(capacity+1, 0);

    //step.2
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    //step.3
    for(int index=1; index<n; index++) {
        for(int w=0; w<=capacity; w++) {
            int include = 0;

            if(weight[index] <= w)
                include = value[index] + prev[w-weight[index]];
            
            int exclude = 0 + prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}


//5. Space optimization : O(N*W), O(W)
int solveOptm2(vector<int> &weight, vector<int> &value, int n, int capacity) {
    
    //step.1
    vector<int> curr(capacity+1, 0);

    //step.2
    for(int w=weight[0]; w<=capacity; w++) {
        if(weight[0] <= capacity)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    //step.3
    for(int index=1; index<n; index++) {
        for(int w=capacity; w>=0; w--) { //solution only possible throungh right to left
            int include = 0;

            if(weight[index] <= w)
                include = value[index] + curr[w-weight[index]];
            
            int exclude = 0 + curr[w];

            curr[w] = max(include, exclude);
        }
    }
    return curr[capacity];
}


int main() {

    vector<int> weight = {1,2,4,5};
    vector<int> value = {5,4,8,6};
    int capacity = 5;
    int n = weight.size();
    int index = n-1;

    // int ans = solveRec(weight, value, index, capacity);
    // cout<<"Max value with capacity is : "<<ans<<endl;


    // vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    // int ans = solveMemo(weight, value, index, capacity, dp);
    // cout<<"Max value with capacity is : "<<ans<<endl;


    // int ans = solveTabu(weight, value, index, capacity);
    
    // int ans = solveOptm(weight, value, index, capacity);

    int ans = solveOptm2(weight, value, index, capacity);
    cout<<"Max value with capacity is : "<<ans<<endl;

    return 0;
}