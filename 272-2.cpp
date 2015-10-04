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
private:
    //binary search, in order traversal, two arrays
    //smaller array stores nearest numbers<target in descending order
    //larger array stores nearest numbers>=target in ascending order
    //O(logN+k);
    void dfs(TreeNode *node, double target, int k, vector<int>& larger, vector<int>& smaller) {
        if(!node) return;
        if(target <= node->val){
            dfs(node->left, target, k, larger, smaller);
            larger.push_back(node->val);
            if(larger.size() >= k) {
                return; //Skip beacuse we only need nearest k numbers
            }
            dfs(node->right, target, k, larger, smaller);
        } else {
            dfs(node->right, target, k, larger, smaller);
            smaller.push_back(node->val);
            if(smaller.size() >= k) {
                return;//Skip beacuse we only need nearest k numbers
            }
            dfs(node->left, target, k, larger, smaller);
        }
    }
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> larger;
        vector<int> smaller;
        vector<int> res;
        dfs(root, target, k, larger, smaller);
        int i = 0;
        int j = 0;
        //merge smaller array and larger array, get the nearest k numbers
        while(res.size() < k){
            if(i == larger.size()) {
                res.push_back(smaller[j]);
                j++;
            } else if(j == smaller.size()) {
                res.push_back(larger[i]);
                i++;
            } else {
                if(larger[i] - target <= target - smaller[j]) {
                    res.push_back(larger[i]);
                    i++;
                } else {
                    res.push_back(smaller[j]);
                    j++;
                }
            }
        }
        return res;
    }
};
