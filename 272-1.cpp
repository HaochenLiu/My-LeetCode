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

/*
Time: O(n*logk)
Space: O(k)
Extra space: O(k)
*/

class Solution {
private:
    void closestK(TreeNode* node, priority_queue<pair<double, int>>& pq, double target, int k) {
        if (node == NULL) return;
        pq.push(make_pair(abs(target - node->val), node->val));
        if (pq.size() > k) pq.pop();
        closestK(node->left, pq, target, k);
        closestK(node->right, pq, target, k);
    }

public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double, int>> pq;
        closestK(root, pq, target, k);
        vector<int> closest;
        while (!pq.empty()) {
            closest.push_back(pq.top().second), pq.pop();
        }
        return closest;
    }
};
