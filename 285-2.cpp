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
 
 /*
Time: O(logn)
Space: O(logn)
Extra space: O(logn)
Assume BST is balanced.
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
        if(root->val == p->val) {
            if(root->right == NULL) {
                return NULL;
            } else {
                TreeNode* node = root->right;
                while(node->left) {
                    node = node->left;
                }
                return node;
            }
        } else if(root->val < p->val) {
            return inorderSuccessorRecur(root->right, NULL, p);
        } else {
            return inorderSuccessorRecur(root->left, root, p);
        }
    }
};
