/*
250. Count Univalue Subtrees

Given a binary tree, count the number of uni-value subtrees.
A Uni-value subtree means all nodes of the subtree have the same value.
For example:
Given binary tree,
             5
             / \
            1   5
           / \   \
          5   5   5


return 4.
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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    bool isUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left == NULL && root->right != NULL) {
            if(root->val == root->right->val && isUnivalSubtrees(root->right)) {
                return true;
            }
            return false;
        }
        
        if(root->left != NULL && root->right == NULL) {
            if(root->val == root->left->val && isUnivalSubtrees(root->left)) {
                return true;
            }
            return false;
        }
        
        if(root->val == root->left->val && root->val == root->right->val && isUnivalSubtrees(root->left) && isUnivalSubtrees(root->right)) {
            return true;
        }
        
        return false;
    }

public:
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(isUnivalSubtrees(root)) {
            return countNodes(root);
        } else {
            int res = 0;
            if(root->left) {
                res += countUnivalSubtrees(root->left);
            }
            if(root->right) {
                res += countUnivalSubtrees(root->right);
            }
            return res;
        }
    }
};
