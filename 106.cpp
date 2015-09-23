/*
106. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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
    TreeNode* buildTreeRecur(vector<int>::iterator ibegin, vector<int>::iterator iend, vector<int>::iterator pbegin, vector<int>::iterator pend) {
        if(ibegin == iend) return NULL;
        int rootval = *(pend - 1);
        vector<int>::iterator rootiter = find(ibegin, iend, rootval);
        TreeNode* root = new TreeNode(rootval);
        root->left = buildTreeRecur(ibegin, rootiter, pbegin, pbegin + (rootiter - ibegin));
        root->right = buildTreeRecur(rootiter + 1, iend, pbegin + (rootiter - ibegin), pend - 1);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        vector<int>::iterator ibegin = inorder.begin();
        vector<int>::iterator iend = inorder.end();
        vector<int>::iterator pbegin = postorder.begin();
        vector<int>::iterator pend = postorder.end();
        return buildTreeRecur(ibegin, iend, pbegin, pend);
    }
};
