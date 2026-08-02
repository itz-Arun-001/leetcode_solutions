/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 *//*
class Solution {
public:
    // inorder wiill always be in sorted order only
    void inorder(TreeNode* root, vector<int>& help) {
        if (root == NULL)
            return;
        inorder(root->left, help);
        help.push_back(root->val);
        inorder(root->right, help);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> help;
        inorder(root, help);
        // sort(help.begin(),help.end());
        return help[k - 1];
    }
};*/

class Solution {
public:
    vector<int> getInorder(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while (cur != NULL) {
            if(cur->left == NULL) {
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else {
                TreeNode* prev = cur->left;
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if(prev->right == NULL) {
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
        int kthSmallest(TreeNode * root, int k) {
            vector<int> help;
           // inorder(root, help);
            // sort(help.begin(),help.end());
            help=getInorder(root);
            return help[k - 1];
        }
};