/*
094. Binary Tree Inorder Traversal
http://www.cnblogs.com/TenosDoIt/p/3445449.html
Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
  1
    \
     2
    /
   3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Morris Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
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
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    res.push_back(cur->val);
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
