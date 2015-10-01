/*
109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
Time: O(n)
Space: O(n)
Extra space: O(logn)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    int getCnt(ListNode* node) {
        int res = 0;
        while(node) {
            node = node->next;
            res++;
        }

        return res;
    }

    TreeNode* sortedListToBSTRecur(ListNode*& head, int beg, int end) {
        if(beg > end) return NULL;
        int mid = beg + (end - beg) / 2;
        TreeNode* leftNode = sortedListToBSTRecur(head, beg, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        root->left = leftNode;
        head = head->next;
        root->right = sortedListToBSTRecur(head, mid + 1, end);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        int cnt = getCnt(head);
        return sortedListToBSTRecur(head, 0, cnt - 1);
    }
};
