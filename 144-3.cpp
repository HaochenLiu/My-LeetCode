/*
144. Binary Tree Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
  1
    \
     2
    /
   3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
Morris Preorder Traversal
Time: O(n)
Space: O(n)
Extra space: O(1)
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
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        vector<int> res;
        while (cur != NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->val);
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
