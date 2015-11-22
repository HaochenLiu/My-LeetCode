/*
308. Range Sum Query 2D - Mutable

Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
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
