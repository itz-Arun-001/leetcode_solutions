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
/*class Solution {

public:
    void sidecheck(TreeNode* node,vector<int>& ans,int l)
    {
        if(node==nullptr) return;
        if(l==ans.size()) ans.push_back(node->val);
        sidecheck(node->left,ans,l+1);
        sidecheck(node->right,ans,l+1);
    }
    int findBottomLeftValue(TreeNode* root) {
         vector<int>ans;
        sidecheck(root,ans,0);
        return ans[ans.size()-1];
        
    }
};*/
class Solution{
    public:
     int findBottomLeftValue(TreeNode* root)
     {
        queue<pair<TreeNode* , int>>q;;
        q.push({root,0});
        int l=-1;
        int ans;
        while(!q.empty())
        {
            auto a=q.front();
            TreeNode* node=a.first;
            q.pop();
            int level=a.second;
            if(level>l)
            {
                ans=node->val;
                l=level;
            }
            if(node->left) q.push({node->left,l+1});
            if(node->right) q.push({node->right,l+1});
        }
        return ans;
     }
};