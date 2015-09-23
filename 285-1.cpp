/*
285. Inorder Successor in BST

Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
Note: If the given node has no in-order successor in the tree, return null.
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
    TreeNode* inorderSuccessorRecur(TreeNode* node, TreeNode* candidate, TreeNode* p) {
        if(node->val == p->val) {
            if(node->right == NULL) {
                return candidate;
            } else {
                TreeNode* res = node->right;
                while(res->left) {
                    res = res->left;
                }
                return res;
            }
        } else if(node->val < p->val) {
            return inorderSuccessorRecur(node->right, candidate, p);
        } else {
            return inorderSuccessorRecur(node->left, node, p);
        }
    }

public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p == NULL || root == NULL) return NULL;
        return inorderSuccessorRecur(root, NULL, p);
    }
};
