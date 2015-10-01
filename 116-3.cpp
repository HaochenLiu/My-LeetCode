/*
116. Populating Next Right Pointers in Each Node

 Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

    You may only use constant extra space.
    You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).

For example,
Given the following perfect binary tree,

        1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/*

/*
Time: O(n)
Space: O(1)
Extra space: O(1)
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* nextHead = NULL;
        TreeLinkNode* nextTail = NULL;
        TreeLinkNode* cur = root;
        while(cur) {
            if(cur->left) {
                if(!nextHead) {
                    nextHead = cur->left;
                    nextTail = cur->left;
                } else {
                    nextTail->next = cur->left;
                    nextTail = nextTail->next;
                }
            }
            if(cur->right) {
                if(!nextHead) {
                    nextHead = cur->right;
                    nextTail = cur->right;
                } else {
                    nextTail->next = cur->right;
                    nextTail = nextTail->next;
                }
            }
            cur = cur->next;
            if(!cur) {
                cur = nextHead;
                nextHead = NULL;
                nextTail = NULL;
            }
        }
        return;
    }
};
