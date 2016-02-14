/*
333. Largest BST Subtree

Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.
Here's an example:
    10
    / \
   5  15
  / \   \ 
 1   8   7
The Largest BST Subtree in this case is the highlighted one. 
The return value is the subtree's size, which is 3.
Hint:

You can recursively use algorithm similar to 98. Validate Binary Search Tree at each node of the tree, which will result in O(nlogn) time complexity.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?
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
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        if(!root)
            return ans;
        bool isbtree = true;
        int maxval = 0, minval = 0, cnt = 0;
        dfs(root, maxval, minval, cnt, isbtree, ans);
        return ans;
    }

private:
    void dfs(TreeNode* root, int &maxval, int &minval, int &cnt, bool &isbtree, int &ans){
        if(!root->left && !root->right){
            ++ cnt;
            ans = max(cnt, ans);
            maxval = minval = root->val;
            return;
        }
        bool iscbtree = true;
        int maxcval = 0, mincval = INT_MIN, lcnt = 0, rcnt = 0;
        maxval = minval = root->val;
        if(root->left){
            dfs(root->left, maxcval, mincval, lcnt, iscbtree, ans);
            if(!iscbtree || maxcval > root->val){
                isbtree = false;
            }
            if(isbtree){
                ans = max(ans, lcnt);
                cnt += lcnt;
                maxval = max(maxval, maxcval);
                minval = min(minval, mincval);
            }
        }
        maxcval = 0, mincval = INT_MIN, iscbtree = true;
        if(root->right){
            dfs(root->right, maxcval, mincval, rcnt, iscbtree, ans);
            if(!iscbtree || mincval < root->val){
                isbtree = false;
            }
            if(isbtree){
                ans = max(ans, rcnt);
                cnt += rcnt;
                maxval = max(maxval, maxcval);
                minval = min(minval, mincval);
            }
        }
        if(!isbtree)
            return;
        ++ cnt;
        ans = max(ans, cnt);
        return ;
    }
};
