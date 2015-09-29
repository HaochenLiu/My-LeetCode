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
Recursion
Time: O(n)
Space: O(n)
Extra space: O(h)
h is depth of the tree. 
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
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root && root->left) inorderTraversal(root->left);
        if(root) res.push_back(root->val);
        if(root && root->right) inorderTraversal(root->right);
        return res;
    }
};
