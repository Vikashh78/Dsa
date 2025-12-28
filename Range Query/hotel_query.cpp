/*There are n hotels on a street. For each hotel you know the number of free rooms. Your task is to assign hotel rooms for groups of tourists. All members of a group want to stay in the same hotel.
The groups will come to you one after another, and you know for each group the number of rooms it requires. You always assign a group to the first hotel having enough rooms. After this, the number of free rooms in the hotel decreases.
Input
The first input line contains two integers n and m: the number of hotels and the number of groups. The hotels are numbered 1,2,\ldots,n.
The next line contains n integers h_1,h_2,\ldots,h_n: the number of free rooms in each hotel.
The last line contains m integers r_1,r_2,\ldots,r_m: the number of rooms each group requires.
Output
Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.
Constraints

1 \le n,m \le 2 \cdot 10^5
1 \le h_i \le 10^9
1 \le r_i \le 10^9

Example
Input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

Output:
3 5 0 1 1
*/

//https://cses.fi/problemset/task/1143/

#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
long long seg[4 * N];
long long ar[N];

// Build segment tree (store max)
void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = ar[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * idx + 1, l, m);
    build(2 * idx + 2, m + 1, r);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

// Update hotel rooms after assigning a group
void update(int idx, int l, int r, int pos, long long val) {
    if (l == r) {
        seg[idx] = val;
        ar[l] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * idx + 1, l, m, pos, val);
    else update(2 * idx + 2, m + 1, r, pos, val);

    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

// Find first hotel with at least 'rooms' available
int findHotel(int idx, int l, int r, long long rooms) {
    if (seg[idx] < rooms) return -1;  // not enough rooms in this segment
    if (l == r) return l;

    int m = (l + r) / 2;
    if (seg[2 * idx + 1] >= rooms)
        return findHotel(2 * idx + 1, l, m, rooms);
    else
        return findHotel(2 * idx + 2, m + 1, r, rooms);
}

int main() {
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ar[i];

    build(0, 0, n - 1);

    while (m--) {
        long long req;
        cin >> req;

        // find hotel
        int pos = findHotel(0, 0, n - 1, req);
        if (pos == -1) {
            cout << 0 << " ";
        } else {
            cout << pos + 1 << " ";
            update(0, 0, n - 1, pos, ar[pos] - req);
        }
    }
    cout << "\n";
    return 0;
}
