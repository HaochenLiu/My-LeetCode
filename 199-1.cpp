/*
199. Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
  1            <---
 /   \
2     3         <---
 \     \
  5     4       <---


You should return [1, 3, 4].
Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        vector<int> record;
        if(root == NULL) return res;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        current.push(root);
        while(!current.empty()) {
            while(!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                record.push_back(node->val);
                if(node->left) {
                    next.push(node->left);
                }
                if(node->right) {
                    next.push(node->right);
                }
            }
            res.push_back(record.back());
            record.clear();
            swap(current, next);
        }

        return res;
    }
};
