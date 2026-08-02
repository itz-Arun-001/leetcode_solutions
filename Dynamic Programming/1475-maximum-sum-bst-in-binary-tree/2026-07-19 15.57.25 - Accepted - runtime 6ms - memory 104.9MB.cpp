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


class nodevalue{
    public:
    int minval;
    int maxval;
    int sum;
       nodevalue(int minv,int maxv,int sum)
    {
        minval=minv;
        maxval=maxv;
        this->sum=sum;
    }
};
class Solution {
    int ans = 0;
    private:
    nodevalue maxbst(TreeNode* root)
    {
        if(!root) return nodevalue(INT_MAX,INT_MIN,0);
        auto left=maxbst(root->left);
        auto right=maxbst(root->right);
        if(left.maxval<root->val&&root->val<right.minval){
            int currsum = left.sum + right.sum + root->val;
ans = max(ans, currsum);
            return nodevalue(min(root->val,left.minval),max(root->val,right.maxval),currsum);
        }
        return nodevalue(INT_MIN,INT_MAX,0);
        
    }
public:
    int maxSumBST(TreeNode* root) {
        maxbst(root);
        return ans;
        
    }
};