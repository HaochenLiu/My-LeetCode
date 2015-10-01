/*
099. Recover Binary Search Tree
http://www.cnblogs.com/xinsheng/p/3468310.html

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.
Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
Time: O(logn)
Space: O(1)
Extra space: O(1)
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* candidate[2];
    TreeNode* pre;
    bool findone;
    bool swapped;

    void inorder(TreeNode *root) {
        if(root == NULL) return;
        if(root->left != NULL && !swapped) {
            inorder(root->left);
        }
         
        if(pre == NULL) {
            pre = root;
        }
        
        if(root->val < pre->val) {
            if(findone) {
                swap(candidate[0]->val, root->val);
                swapped = true;
            } else {
                candidate[0] = pre;
                candidate[1] = root;
                findone = true;
            }
        }
        
        pre = root;
        if(root->right && !swapped) {
            inorder(root->right);
        }
    }
    
public:
    void recoverTree(TreeNode *root) {
        if(root == NULL) return;
        swapped = false;
        findone = false;
        pre = NULL;
        inorder(root);
        if(!swapped) {
            swap(candidate[0]->val, candidate[1]->val);
        }

        return;
    }
};
