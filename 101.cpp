/*
101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

   1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:

   1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Time: O(n)
Space: O(logn)
Extra space: O(logn)
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
    bool isSymmetric(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 != NULL && root2 == NULL) return false;
        if(root1 == NULL && root2 != NULL) return false;
        if(root1->val != root2->val) return false;
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left != NULL && root->right == NULL) return false;
        if(root->left == NULL && root->right != NULL) return false;
        return isSymmetric(root->left, root->right);
    }
};
