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
Space: O(b)
b is width of the tree. 
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
        if(root == NULL)return;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *pre = NULL;
        while(!q.empty()) {
            TreeLinkNode *cur = q.front();
            q.pop();
            if(cur) {
                if(cur->left) {
                    q.push(cur->left);
                }
                
                if(cur->right) {
                    q.push(cur->right);
                }
            } else if(!q.empty()) {
                q.push(NULL);
            }

            if(pre != NULL) {
                pre->next = cur;
            }
            pre = cur;
        }
    }
};
