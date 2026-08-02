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
 */

class bsi {
    stack<TreeNode*> s;
    bool reverse;

public:
    bsi(TreeNode* node, bool rev) {
        reverse = rev;

        pushall(node);

    }
    void pushall(TreeNode* node) {
        while (node != NULL) {
            s.push(node);
            if (reverse)
                node = node->right;
            else
                node = node->left;
        }
    }
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        if (reverse)
            pushall(temp->left);
        else
            pushall(temp->right);
        return temp->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;
        bsi l(root, false);
        bsi r(root, true);
        int left = l.next();
        int right = r.next();
        while (left < right) {
            if (left + right == k)
                return true;
            else if (left + right < k)
                left = l.next();
            else
                right = r.next();
        }
        return false;
    }
};