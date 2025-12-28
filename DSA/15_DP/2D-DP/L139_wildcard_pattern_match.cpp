//Leetcode : 44
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //recursive solution
    bool solve(string& str, string& pattern, int i, int j) {
        //base case
        if(i<0 && j<0) //matched
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0) {
            for(int k=j; k>=0; k--) {
                if(pattern[k] != '*')
                    return false;
            }
            return true; //char is a '*'
        }

        if(str[i] == pattern[j] || pattern[j] == '?') {
            return solve(str, pattern, i-1, j-1);
        }
        else if(pattern[j] == '*') {
            return (solve(str, pattern, i, j-1) || solve(str, pattern, i-1, j));
        }
        else {
            return false;
        }
    }

    //Top down DP
    bool solveMemo(string& str, string& pattern, int i, int j, vector<vector<int>> &dp) {
        //base case
        if(i<0 && j<0) //matched
            return true;
        if(i>=0 && j<0)
            return false;
        if(i<0 && j>=0) {
            for(int k=j; k>=0; k--) {
                if(pattern[k] != '*')
                    return false;
            }
            return true; //char is a '*'
        }

        //step.3
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(str[i] == pattern[j] || pattern[j] == '?') {
            return solveMemo(str, pattern, i-1, j-1, dp);
        }
        else if(pattern[j] == '*') {
            dp[i][j] = (solveMemo(str, pattern, i, j-1, dp) || solveMemo(str, pattern, i-1, j, dp));
        }
        else {
            dp[i][j] = false;
        }
        
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        // return solve(s, p, s.size()-1, p.size()-1);

        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return solveMemo(s, p, s.size()-1, p.size()-1, dp);
    }
};

int main() {

    return 0;
}