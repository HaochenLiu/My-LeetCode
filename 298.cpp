/*
298. Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).

For example,
   1
    \
     3
    / \
   2   4
        \
         5
Longest consecutive sequence path is 3-4-5, so return 3.
   2
    \
     3
    / 
   2    
  / 
 1
Longest consecutive sequence path is 2-3,not3-2-1, so return 2.
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
    void longestConsecutiveRecur(TreeNode* root, int len, int& maxLen) {
        int t = len;
        if(root->left) {
            if(root->left->val == root->val + 1) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }
            longestConsecutiveRecur(root->left, len, maxLen);
        } 

        len = t;
        if(root->right) {
            if(root->right->val == root->val + 1) {
                len++;
                maxLen = max(maxLen, len);
            } else {
                len = 1;
            }
            longestConsecutiveRecur(root->right, len, maxLen);
        } 
    }

public:
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        int maxLen = 1;
        longestConsecutiveRecur(root, 1, maxLen);
        return maxLen;
    }
};
