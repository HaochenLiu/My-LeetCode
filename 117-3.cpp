/*
117. Populating Next Right Pointers in Each Node II

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

        1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
*/

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
