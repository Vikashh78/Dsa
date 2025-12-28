#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//This question is upgreded version of LIS -----
class solution {
    public:
    // Check if 'a' can fit inside 'b'
    static bool check(vector<int> &a, vector<int> &b) {
        return (
            a[0]>b[0] && a[1]>b[1]
        );
    }

    // Comparator for lower_bound: compare by height only
    static bool cmpHeight(const vector<int>& a, const vector<int>& b) {
        return a[1]<b[1];
    }

    int solve(vector<vector<int>>& envelopes, int n) {
        vector<vector<int>> ans;
        ans.push_back(envelopes[0]);

        for(int i=1; i<n; i++) {
            if(check(envelopes[i], ans.back())) {
                ans.push_back(envelopes[i]);
            }
            else {
                int index = lower_bound(ans.begin(), ans.end(), envelopes[i], cmpHeight) - ans.begin();
                if(index == ans.size()) ans.push_back(envelopes[i]);
                else ans[index] = envelopes[i];
            }
        }
        return ans.size();
    }

};

int main() {

    solution obj;
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    int n = envelopes.size();
    //width- a[0], height- a[1]
    //step.1 - sorting the input array width by increasing order, nd then height by decreasing order

    sort(envelopes.begin(), envelopes.end(), 
        [](auto &a, auto &b){
            if(a[0] == b[0]) return a[1]>b[1];
            return a[0]<b[0];
    });

    int x = obj.solve(envelopes, n);
    cout<<x<<endl;

    return 0;
}