/*
272. Closest Binary Search Tree Value II

Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
Note:
Given target value is a floating point.
You may assume k is always valid, that is: k ≤ total nodes.
You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
Follow up:
Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
Hint:
Consider implement these two helper functions:
getPredecessor(N), which returns the next smaller node to N.
getSuccessor(N), which returns the next larger node to N.
Try to assume that each node has a parent pointer, it makes the problem much easier.
Without parent pointer we just need to keep track of the path from the root to the current node using a stack.
You would need two stacks to track the path in finding predecessor and successor node separately.
*/

class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> closest(k, 0);
        stack<int> pre;
        stack<int> suc;
        inorder(root, target, false, pre);
        inorder(root, target, true, suc);
        for (int i = 0; i < k; i++) {
            if(pre.empty()) {
                closest[i] = suc.top();
                suc.pop();
            } else if(suc.empty()) {
                closest[i] = pre.top();
                pre.pop();
            } else if(abs(target - pre.top()) < abs(target - suc.top())) {
                closest[i] = pre.top();
                pre.pop();
            } else {
                closest[i] = suc.top();
                suc.pop();
            }
        }

        return closest;
    }
private:
    void inorder(TreeNode* root, double target, bool reversed, stack<int>& s) {
        if (root == NULL) return;
        if(reversed) {
            inorder(root->right, target, reversed, s);
        } else {
            inorder(root->left, target, reversed, s);
        }
        if ((reversed && root->val <= target) || (!reversed && root->val > target)) {
            return;
        }
        s.push(root -> val);
        if(reversed) {
            inorder(root->left, target, reversed, s);
        } else {
            inorder(root->right, target, reversed, s);
        }
    }
};
