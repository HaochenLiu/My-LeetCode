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
Extra space: O(b)
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
    void connect(TreeLinkNode* root) {
        vector<vector<TreeLinkNode*>> res;
        vector<TreeLinkNode*> record;
        if(root == NULL) return;
        queue<TreeLinkNode*> current;
        queue<TreeLinkNode*> next;
        current.push(root);
        while(!current.empty()) {
            while(!current.empty()) {
                TreeLinkNode* node = current.front();
                current.pop();
                record.push_back(node);
                if(node->left) {
                    next.push(node->left);
                }
                if(node->right) {
                    next.push(node->right);
                }
            }
            res.push_back(record);
            record.clear();
            swap(current, next);
        }
        
        for(int i = 0; i < res.size(); i++) {
            for(int j = 0; j < res[i].size() - 1; j++) {
                res[i][j]->next = res[i][j + 1];
            }
            res[i][res[i].size() - 1]->next = NULL;
        }
        
        return;
    }
};
