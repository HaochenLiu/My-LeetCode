/*
314. Binary Tree Vertical Order Traversal

Given a binary tree, return the vertical order traversal of its nodes' values. (ie, from top to bottom, column by column).

If two nodes are in the same row and column, the order should be from left to right.

Examples:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its vertical order traversal as:

[
  [9],
  [3,15],
  [20],
  [7]
]

Given binary tree [3,9,20,4,5,2,7],

    _3_
   /   \
  9    20
 / \   / \
4   5 2   7

return its vertical order traversal as:

[
  [4],
  [9],
  [3,5,2],
  [20],
  [7]
]
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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        unordered_map<TreeNode*, int> idxm;
        idxm[root] = 0;
        unordered_map<int, vector<int>> m;
        int minVal = 0;
        int maxVal = 0;
        queue<TreeNode*> cur; 
        queue<TreeNode*> next;
        cur.push(root);

        while(!cur.empty()) {
            while(!cur.empty()) {
                TreeNode* node = cur.front();
                cur.pop();
                int idx = idxm[node];
                m[idx].push_back(node->val);
                if(node->left) {
                    idxm[node->left] = idx - 1;
                    minVal = min(minVal, idx - 1);
                    next.push(node->left);
                }
                if(node->right) {
                    idxm[node->right] = idx + 1;
                    maxVal = max(maxVal, idx + 1);
                    next.push(node->right);
                }
            }
            swap(cur, next);
        }
            
        for(int i = minVal; i <= maxVal; i++) {
            res.push_back(m[i]);
        }
    
        return res;
    }
};
