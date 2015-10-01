/*
109. Convert Sorted List to Binary Search Tree

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
Time: O(nlogn)
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

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        int cnt = getCnt(head);
        if(cnt == 1) {
            TreeNode* root = new TreeNode(head->val);
            root->left = NULL;
            root->right = NULL;
            return root;
        }

        ListNode* cur = head;
        for(int i = 0; i < cnt / 2 - 1; i++) {
            cur = cur->next;
        }
        ListNode* mid = cur->next;
        cur->next = NULL;
        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
        return root;
    }
};
