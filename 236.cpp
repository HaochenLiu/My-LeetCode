/*
236. Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
       _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4


For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
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
    bool getPath(TreeNode* root, TreeNode* p, stack<TreeNode*>& st) {
        if(root == NULL) return false;
        if(root == p) {
            st.push(root);
            return true;
        }

        if(getPath(root->left, p, st) || getPath(root->right, p, st)) {
            st.push(root);
            return true;
        }

        return false;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(p == q) return p;
        stack<TreeNode*> pSt;
        stack<TreeNode*> qSt;
        getPath(root, p, pSt);
        getPath(root, q, qSt);
        TreeNode* res = NULL;
        
        while(true) {
            if(!pSt.empty() && !qSt.empty() && pSt.top() == qSt.top()) {
                res = pSt.top();
                pSt.pop();
                qSt.pop();
            } else {
                break;
            }
        }
        
        return res;
    }
};
