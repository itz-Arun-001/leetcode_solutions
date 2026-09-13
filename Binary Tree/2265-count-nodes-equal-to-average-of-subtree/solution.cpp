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
    unordered_map<TreeNode*,int>sum,count;
    void help(TreeNode* node,int& cnt)
    {   if(node==NULL) return ;
        help(node->left,cnt);
        help(node->right,cnt);
        sum[node]=node->val+sum[node->left]+sum[node->right];
        count[node]=count[node->left]+count[node->right]+1;
        if(node->val==(sum[node]/count[node])) cnt++;

    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        help(root,cnt);
        return cnt;
    }
};
