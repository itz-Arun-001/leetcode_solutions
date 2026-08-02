/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void sidecheck(TreeNode* node,vector<int>& ans,int l)
    {
        if(node==nullptr) return;
        if(l==ans.size()) ans.push_back(node->val);
        sidecheck(node->right,ans,l+1);
        sidecheck(node->left,ans,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        sidecheck(root,ans,0);
        return ans;
        
    }
};