/*
366. Find Leaves of Binary Tree

Given a binary tree, find all leaves and then remove those leaves. Then repeat the previous steps until the tree is empty.

Example:
Given binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].

Explanation:
1. Remove the leaves [4, 5, 3] from the tree

          1
         / 
        2          
2. Remove the leaf [2] from the tree

          1          
3. Remove the leaf [1] from the tree

          []         
Returns [4, 5, 3], [2], [1].

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        TreeNode dummy(0);
        dummy.left = root;
    
        while (dummy.left!=NULL) {
            vector<int> leaves;
            dfs(root, &dummy, true, leaves);
            ret.push_back(leaves);
        }
        return ret;
    }
    
    void dfs(TreeNode* root, TreeNode* parent, bool isLeft, vector<int>& leaves) {
        if (root->left==NULL && root->right==NULL) {
            leaves.push_back(root->val);
            if (isLeft) parent->left = NULL;
            else parent->right = NULL;
            return;
        }
        if (root->left) dfs(root->left, root, true, leaves);
        if (root->right) dfs(root->right, root, false, leaves);
        return;
    }
};
