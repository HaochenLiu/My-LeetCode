/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

/*
preorder, inorder, postorder, level order四种traversal中。inorder加上任何其他一种，便可复原整个树。其他组合则不能复原。
*/

/*
Time: O(n)
Space: O(n)
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
    TreeNode* buildTreeRecur(vector<int>::iterator ibegin, vector<int>::iterator iend, vector<int>::iterator pbegin, vector<int>::iterator pend) {
        if(ibegin == iend) return NULL;
        int rootval = *pbegin;
        vector<int>::iterator rootiter = find(ibegin, iend, rootval);
        TreeNode* root = new TreeNode(rootval);
        root->left = buildTreeRecur(ibegin, rootiter, pbegin + 1, pbegin + 1 + (rootiter - ibegin));
        root->right = buildTreeRecur(rootiter + 1, iend, pbegin + 1 + (rootiter - ibegin), pend);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        vector<int>::iterator ibegin = inorder.begin();
        vector<int>::iterator iend = inorder.end();
        vector<int>::iterator pbegin = preorder.begin();
        vector<int>::iterator pend = preorder.end();
        return buildTreeRecur(ibegin, iend, pbegin, pend);
    }
};
