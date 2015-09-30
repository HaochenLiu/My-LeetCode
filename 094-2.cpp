/*
094. Binary Tree Inorder Traversal
http://www.cnblogs.com/TenosDoIt/p/3445449.html

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},

  1
    \
     2
    /
   3

return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Iteration
Time: O(n)
Space: O(n)
Extra space: O(h)
h is the height of the tree.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(!st.empty() || node) {
            if(node != NULL) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};
