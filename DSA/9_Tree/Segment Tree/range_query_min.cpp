#include <iostream> 
#include <limits.h>
using namespace std;

//build function
void buildTree(int *tree, int *arr, int idx, int s, int e) {
    //base case
    if(s > e) return;
    if(s == e) {
        tree[idx] = arr[s];
        return;
    }

    int mid = s + (e - s) / 2;

    buildTree(tree, arr, 2*idx, s, mid);        //build left subtree
    buildTree(tree, arr, 2*idx+1, mid+1, e);    //build right subtree

    tree[idx] = min(tree[2*idx], tree[2*idx+1]);  //internal node stores min of children
}


//query function
int query(int *tree, int idx, int s, int e, int l, int r) {

    //case 1 : No overlap
    if(r < s || l > e) return INT_MAX;

    //case 2 : Complete overlap
    if(l <= s && e <= r) return tree[idx];

    //case 3 : Partial overlap
    int mid = s + (e - s) / 2;
    int left = query(tree, 2*idx, s, mid, l, r);
    int right = query(tree, 2*idx+1, mid+1, e, l, r);

    return min(left, right);
}


//update function (point update)
void update(int *tree, int idx, int s, int e, int i, int nv) {
    //no overlap
    if(i < s || i > e) return;

    //reached leaf node
    if(s == e) {
        tree[idx] = nv;
        return;
    }

    //i lying in range s and e
    int mid = (s + e) / 2;
    update(tree, 2*idx, s, mid, i, nv);
    update(tree, 2*idx+1, mid+1, e, i, nv);

    tree[idx] = min(tree[2*idx], tree[2*idx+1]);    //update current node
    return;
}


//Range update : increase each value in [l, r] by 'inc'
void rangeUpdate(int *tree, int idx, int s, int e, int l, int r, int inc) {
    //no overlap
    if(r < s || l > e) return;

    //leaf node
    if(s == e) {
        tree[idx] += inc;
        return;
    }
    int mid = (s + e) / 2;
    //range lies in subtree
    rangeUpdate(tree, 2*idx, s, mid, l, r, inc);
    rangeUpdate(tree, 2*idx+1, mid+1, e, l, r, inc);

    //update current node
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
}


int main() {

    int arr[] = {1,3,2,6,-4,5};
    int n = sizeof(arr)/sizeof(int);

    int *tree = new int[4*n + 1];    //dynamically allocated tree
    int idx = 1;
    int s = 0;
    int e = n - 1;

    buildTree(tree, arr, idx, s, e);     //build the tree

    int Q;
    cin >> Q;

    while(Q--) {

        int type;
        cin >> type;

        if(type == 1) {
            // Range Query
            int l, r;
            cin >> l >> r;
            cout << "Min element in range = "
                 << query(tree, 1, s, e, l, r) << endl;
        }

        else if(type == 2) {
            // Point update
            int i, nv;
            cin >> i >> nv;
            update(tree, 1, s, e, i, nv);
        }

        else if(type == 3) {
            // Range update
            int l, r, inc;
            cin >> l >> r >> inc;
            rangeUpdate(tree, 1, s, e, l, r, inc);
        }
    }

    return 0;
}
