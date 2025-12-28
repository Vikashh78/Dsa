//Approch : make a copy of given string and reverse it. Now this problm became longest common subsequence : bcoz a palindromic string is same as its reverse

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

     int solveMemo(string &text1, string &text2, int i, int j, vector<vector<int>>& dp) {
        //base case
        if(i>=text1.size() || j>=text2.size()) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // for matching
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1+ solveMemo(text1, text2, i+1, j+1, dp);
        }
        //not matching
        else {
            return dp[i][j] = max(solveMemo(text1, text2, i+1, j, dp), solveMemo(text1, text2, i, j+1, dp));
        }
    }


    //this is the most optimized code from longest common subsequence
    int solve(string &text1, string &text2) {
        int n = text1.size(), m = text2.size();
        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        int ans = 0;
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                //matching
                if(text1[i] == text2[j]) {
                    ans = 1+ next[j+1];
                }
                //not matching
                else {
                    ans = max(next[j], curr[j+1]);
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0]; // curr array is just above the next array, so according to 0 we are returning next.
    }

int longestPalindromeSubseq(string s) {
    string revStr = s;
    reverse(revStr.begin(), revStr.end());  //main catch, given string ka ek reversed copy bna liya

    // vector<vector<int>> dp(s.size(), vector<int>(revStr.size(), -1));
    // return solveMemo(s, revStr, 0, 0, dp);

    return solve(s, revStr);
}

int main() {

    string s;
    cin>> s;

    int ans = longestPalindromeSubseq(s);
    cout<<ans<<endl;

    return 0;
}