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

class KDTree {
public:
    int depth;
    int sum;
    int row1;
    int row2;
    int col1;
    int col2;
    KDTree* left;
    KDTree* right;
};

KDTree* createKDTree(vector<vector<int>> &matrix, int d, int r1, int r2, int c1, int c2) {
    KDTree* t = new KDTree();
    t->depth = d;
    t->row1 = r1;
    t->row2 = r2;
    t->col1 = c1;
    t->col2 = c2;
    if(r1 == r2 && c1 == c2) {
        t->sum = matrix[r1][c1];
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    
    if(d % 2 == 1) {
        if(r1 == r2) {
            t->left = createKDTree(matrix, d + 1, r1, r2, c1, c2);
            t->right = NULL;
            t->sum = t->left->sum;
        } else {
            t->left = createKDTree(matrix, d + 1, r1, r1 + (r2 - r1) / 2, c1, c2);
            t->right = createKDTree(matrix, d + 1, r1 + (r2 - r1) / 2 + 1, r2, c1, c2);
            t->sum = t->left->sum + t->right->sum;
        }
    } else {
        if(c1 == c2) {
            t->left = createKDTree(matrix, d + 1, r1, r2, c1, c2);
            t->right = NULL;
            t->sum = t->left->sum;
        } else {
            t->left = createKDTree(matrix, d + 1, r1, r2, c1, c1 + (c2 - c1) / 2);
            t->right = createKDTree(matrix, d + 1, r1, r2, c1 + (c2 - c1) / 2 + 1, c2);
            t->sum = t->left->sum + t->right->sum;
        }
    }

    return t;
}

class NumMatrix {
private:
    KDTree* t = NULL;
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            t = NULL;
        } else {
            t = createKDTree(matrix, 1, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
        }
        v = matrix;
        return;
    }

    void update(int row, int col, int val) {
        if(row < 0 || row >= v.size()) return;
        if(col < 0 || col >= v[0].size()) return;
        if(v[row][col] == val) return;

        int delta = val - v[row][col];
        v[row][col] = val;
        KDTree* node = t;
        while(node) {
            node->sum += delta;
            if(node->depth % 2 == 1) {
                if(node->row1 == node->row2) {
                    node = node->left;
                } else {
                    if(row < node->right->row1) {
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                }
            } else {
                if(node->col1 == node->col2) {
                    node = node->left;
                } else {
                    if(col < node->right->col1) {
                        node = node->left;
                    } else {
                        node = node->right;
                    }
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 > row2) return 0;
        if(row1 < 0) return 0;
        if(row2 >= v.size()) return 0;
        if(col1 > col2) return 0;
        if(col1 < 0) return 0;
        if(col2 >= v[0].size()) return 0;
        if(row1 == row2 && col1 == col2) return v[row1][col1];

        return sumRegionRecur(t, row1, row2, col1, col2);
    }

    int sumRegionRecur(KDTree* node, int row1, int row2, int col1, int col2) {
        if(node == NULL) return 0;
        if(row2 < node->row1) return 0;
        if(row1 > node->row2) return 0;
        if(col2 < node->col1) return 0;
        if(col1 > node->col2) return 0;
        if(node->row1 == row1 && node->row2 == row2 && node->col1 == col1 && node->col2 == col2) return node->sum;

        if(node->depth % 2 == 1) {
            if(node->row1 == node->row2) {
                return sumRegionRecur(node->left, row1, row2, col1, col2);
            } else {
                if(row1 > node->left->row2) return sumRegionRecur(node->right, row1, row2, col1, col2);
                if(row2 < node->right->row1) return sumRegionRecur(node->left, row1, row2, col1, col2);
                return sumRegionRecur(node->left, row1, node->left->row2, col1, col2) + sumRegionRecur(node->right, node->right->row1, row2, col1, col2);
            }
        } else {
            if(node->col1 == node->col2) {
                return sumRegionRecur(node->left, row1, row2, col1, col2);
            } else {
                if(col1 > node->left->col2) return sumRegionRecur(node->right, row1, row2, col1, col2);
                if(col2 < node->right->col1) return sumRegionRecur(node->left, row1, row2, col1, col2);
                return sumRegionRecur(node->left, row1, row2, col1, node->left->col2) + sumRegionRecur(node->right, row1, row2, node->right->col1, col2);
            }
        }
    }
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
