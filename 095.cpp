/*
095. Unique Binary Search Trees II

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

  1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Time: O(2^n)
Space: O(2^n)
Extra space: O(2^n)
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
    vector<TreeNode*> createTree(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            root->left = NULL;
            root->right = NULL;
            res.push_back(root);
            return res;
        }
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> leftTree = createTree(start, i - 1);
            vector<TreeNode*> rightTree = createTree(i + 1, end);
            for(int j = 0; j < leftTree.size(); j++) {
                for(int k = 0; k < rightTree.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1, n);
    }
};
