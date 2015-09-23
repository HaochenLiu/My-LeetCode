/*
222. Count Complete Tree Nodes

Given a complete binary tree, count the number of nodes.
Definition of a complete binary tree from Wikipedia:
http://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
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
    int getLeftDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        while(root) {
            root = root->left;
            res++;
        }
        
        return res;
    }

    int getRightDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int res = 0;
        while(root) {
            root = root->right;
            res++;
        }
        
        return res;
    }

public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int l = getLeftDepth(root);
        int r = getRightDepth(root);
        if(l == r) {
            return (1<<l) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};
