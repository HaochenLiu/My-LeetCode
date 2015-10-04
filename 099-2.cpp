/*
099. Recover Binary Search Tree

http://www.cnblogs.com/xinsheng/p/3468310.html
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        TreeNode* pre = NULL;
        TreeNode* par = NULL;
        TreeNode* candidate[2];
        candidate[0] = NULL;
        candidate[1] = NULL;
        bool findone = false;

        while(cur) {
            if(cur->left == NULL) {
                if(par && par->val > cur->val) {
                    if(!findone) {
                        findone = true;
                        candidate[0] = par;
                    } 
                    candidate[1] = cur;
                }
                par = cur;
                cur = cur->right;
            } else {
                pre = cur->left;
                while(pre->right != NULL && pre->right != cur) {
                    pre = pre->right;
                }
                if(pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    if(par && par->val > cur->val) {
                        if(!findone) {
                            findone = true;
                            candidate[0] = par;
                        } 
                        candidate[1] = cur;
                    }
                    pre->right = NULL;
                    par = cur;
                    cur = cur->right;
                }
            }
        }
        
        swap(candidate[0]->val, candidate[1]->val);
        
        return;
    }
};
