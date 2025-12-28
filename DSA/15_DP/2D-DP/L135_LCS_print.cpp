#include <bits/stdc++.h>
using namespace std;
//we have to print longest common subsequence : watch striver a2z sheet

void lcs(string& s1, string& s2) { 
    // LCS logic
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // only change i am running loop from 1 to n 
    for(int i=1; i<=n; i++) { //this logic is from striver a2z
        for(int j=1; j<=m; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    int len = dp[n][m]; //this is the length of LCS
    string ans(len, '$');

    //Printing logic : returning from dp[n][m] to dp[0][0]
    int idx = len-1;
    int i = n, j = m;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) { //matched
            ans[idx] = s1[i-1]; //only including commom char
            idx--;
            i--, j--; //return to diagonal of dp table
        }
        else if(dp[i-1][j] > dp[i][j-1]) { 
            i--; //return to prev row
        }
        else {
            j--; //return to prev col
        }
    }

    cout<<ans<<endl;
}

int main() {
    string s1, s2;
    cin>>s1 >>s2;

    lcs(s1, s2);

    return 0;
}