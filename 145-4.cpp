/*
145. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

  1
    \
     2
    /
   3

return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

/*
Morris Postorder Traversal
Time: O(n)
Space: O(n)
Extra space: O(1)
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
    void reverse(TreeNode *from, TreeNode *to) {
        if (from == to) return;
        TreeNode* x = from;
        TreeNode* y = from->right;
        TreeNode* z;
        while (true) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if (x == to) {
                break;
            }
        }
    }
    
    void printReverse(TreeNode* from, TreeNode *to, vector<int>& res) {
        reverse(from, to);
        TreeNode *p = to;
        while (true) {
            res.push_back(p->val);
            if (p == from) {
                break;
            }
            p = p->right;
        }
        reverse(to, from);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(0);
        dummy.left = root;
        TreeNode *cur = &dummy, *prev = NULL;
        while (cur) {
            if (cur->left == NULL) {
                cur = cur->right;
            } else {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                } else {
                    printReverse(cur->left, prev, res);
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};
