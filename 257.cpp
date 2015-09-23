/*
257. Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
  1
 /   \
2     3
 \
  5


All root-to-leaf paths are:
["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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
    void binaryTreePathsRecur(TreeNode* node, string cur, vector<string> &res) {
        if(node == NULL) return;

        if(node->left == NULL && node->right == NULL) {
            cur += "->";
            cur += to_string(node->val);
            res.push_back(cur);
            binaryTreePathsRecur(node->right, cur, res);
            return;
        } else if(node->left != NULL && node->right == NULL) {
            cur += "->";
            cur += to_string(node->val);
            binaryTreePathsRecur(node->left, cur, res);
            return;
        } else if(node->left == NULL && node->right != NULL) {
            cur += "->";
            cur += to_string(node->val);
            binaryTreePathsRecur(node->right, cur, res);
            return;
        } else {
            cur += "->";
            cur += to_string(node->val);
            binaryTreePathsRecur(node->left, cur, res);
            binaryTreePathsRecur(node->right, cur, res);
        }
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL) return res;
        if(root->left == NULL && root->right == NULL) {
            res.push_back(to_string(root->val));
            return res;
        }
        binaryTreePathsRecur(root->left, to_string(root->val), res);
        binaryTreePathsRecur(root->right, to_string(root->val), res);

        return res;
    }
};
