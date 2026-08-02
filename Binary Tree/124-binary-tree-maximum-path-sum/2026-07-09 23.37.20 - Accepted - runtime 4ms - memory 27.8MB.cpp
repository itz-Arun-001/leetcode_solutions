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
    int path(TreeNode* node,int &maxsum)
    {
        if(node==NULL) return 0;
        int ls=max(0,path(node->left,maxsum));
        int rs=max(0,path(node->right,maxsum));
        maxsum=max(maxsum,ls+rs+node->val);
        return max(ls,rs)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        path(root,maxsum);
        return maxsum;
        
    }
};