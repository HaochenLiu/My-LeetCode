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
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;

        queue<TreeNode*> q;
        TreeNode* prev = root;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL) {
                res.push_back(prev->val);
                if(q.empty()) {
                    break;
                } else {
                    q.push(NULL);
                }
            } else {
                if(cur->left != NULL) {
                    q.push(cur->left);
                }
                if(cur->right != NULL) {
                    q.push(cur->right);
                }
            }
            prev = cur;
        }
        return res;
    }
};
