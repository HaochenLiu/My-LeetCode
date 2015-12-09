/*
315. Count of Smaller Numbers After Self

You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

Return the array [2, 1, 1, 0]. 
*/

class BSTNode {
public:
    BSTNode* left;
    BSTNode* right;
    int val;
    int count;
    int leftSize;
    
    BSTNode(int v) {
        left = NULL;
        right = NULL;
        val = v;
        count = 1;
        leftSize = 0;
    }
};

void insert(BSTNode* root, int v) {
    BSTNode* node = root;
    int res = 0;
    while(true) {
        if(node->val == v) {
            node->count++;
            break;
        } else if(node->val > v) {
            node->leftSize++;
            if(node->left != NULL) {
                node = node->left;
            } else {
                node->left = new BSTNode(v);
                break;
            }
        } else {
            if(node->right != NULL) {
                node = node->right;
            } else {
                node->right = new BSTNode(v);
                break;
            }
        }
    }
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.empty()) return vector<int>{};
        int n = nums.size();
        vector<int> res(n, 0);
        BSTNode* root = new BSTNode(nums[n - 1]);
        res[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            res[i] = searchSmaller(root, nums[i]);
            insert(root, nums[i]);
        }

        return res;
    }
    
    int searchSmaller(BSTNode* root, int v) {
        BSTNode* node = root;
        int res = 0;
        while(node) {
            if(node->val >= v) {
                node = node->left;
            } else {
                res += node->leftSize + node->count;
                node = node->right;
            }
        }
        return res;
    }
};
