/*
297. Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if(root == NULL) return "#";
        res += to_string(root->val);
        res.append(1, ',');
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                res += to_string(node->left->val);
                res.append(1, ',');
                q.push(node->left);
            } else {
                res += "#";
                res.append(1, ',');
            }

            if(node->right) {
                res += to_string(node->right->val);
                res.append(1, ',');
                q.push(node->right);
            } else {
                res += "#";
                res.append(1, ',');
            }
        }

        return res.substr(0, res.size() - 1);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data == "#") return NULL;

        queue<TreeNode*> q;
        int idx = 0;
        int pos = data.find(',', idx);
        int val = stoi(data.substr(idx, pos - idx));
        root = new TreeNode(val);
        root->left = NULL;
        root->right = NULL;
        
        if(pos == string::npos) {
            return root;
        } else {
            idx = pos + 1;
            q.push(root);
        }

        bool flag = true;
        TreeNode* node;
        while(idx < data.length()) {
            if(flag) {
                node = q.front();
                q.pop();
            }
            flag = !flag;
            
            pos = data.find(',', idx);
            if(pos == string::npos) break;
            if(data.substr(idx, pos - idx) != "#") {
                val = stoi(data.substr(idx, pos - idx));
                if(!flag) {
                    node->left = new TreeNode(val);
                    node->left->left = NULL;
                    node->left->right = NULL;
                    q.push(node->left);
                } else {
                    node->right = new TreeNode(val);
                    node->right->left = NULL;
                    node->right->right = NULL;
                    q.push(node->right);
                }
            }
            idx = pos + 1;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
