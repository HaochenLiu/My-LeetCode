/*
113. Path Sum II

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
For example:
Given the below binary tree and sum = 22,
             5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/*
Time: O(n)
Space: O(logn+k)
Extra space: O(logn)
k is the number of solutions.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void pathSumRecur(TreeNode* node, vector<vector<int>> &res,  vector<int> record, int sum) {
        if(node == NULL) return;
        if(node->left == NULL && node->right == NULL) {
            if(sum == node->val) {
                record.push_back(node->val);
                res.push_back(record);
            }
            return;
        }
        record.push_back(node->val);
        pathSumRecur(node->left, res, record, sum - node->val);
        pathSumRecur(node->right, res, record, sum - node->val);

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> record;
        if(root == NULL) return res;
        pathSumRecur(root, res, record, sum);
        return res;
    }
};
