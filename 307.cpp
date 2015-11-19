/*
307. Range Sum Query - Mutable

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Note:

    The array is only modifiable by the update function.
    You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class SegmentTree {
public:
    int low;
    int high;
    int sum;
    SegmentTree* left;
    SegmentTree* right;
};

SegmentTree* createSegmentTree(vector<int>& v, int l, int h) {
    SegmentTree* t = new SegmentTree();
    t->low = l;
    t->high = h;
    
    if(l == h) {
        t->sum = v[l];
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    
    t->left = createSegmentTree(v, l, l + (h - l) / 2);
    t->right = createSegmentTree(v, l + (h - l) / 2 + 1, h);
    t->sum = t->left->sum + t->right->sum;
    return t;
}

class NumArray {
private:
    SegmentTree* t = NULL;
    vector<int> v;
public:
    NumArray(vector<int> &nums) {
        if(nums.empty()) {
            t = NULL;
        } else {
            t = createSegmentTree(nums, 0, nums.size() - 1);
        }
        v = nums;
        return;
    }

    void update(int i, int val) {
        if(i < 0 || i >= v.size()) return;
        if(v[i] == val) return;
        int delta = val - v[i];
        v[i] = val;
        SegmentTree* node = t;
        while(true) {
            if(i >= node->low && i <= node->high) {
                node->sum += delta;
            }
            if(node->low == node->high) {
                break;
            }
            if(i <= node->left->high) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        return;
    }

    int sumRangeRecur(SegmentTree* node, int i, int j) {
        if(node->low == i && node->high == j) return node->sum;
        if(i > node->left->high) return sumRangeRecur(node->right, i, j);
        if(j < node->right->low) return sumRangeRecur(node->left, i, j);
        return sumRangeRecur(node->left, i, node->left->high) + sumRangeRecur(node->right, node->right->low, j);
    }

    int sumRange(int i, int j) {
        if(i > j) return 0;
        if(i < 0) return 0;
        if(j >= v.size()) return 0;
        if(i == j) return v[i];
        return sumRangeRecur(t, i, j);
    }
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
