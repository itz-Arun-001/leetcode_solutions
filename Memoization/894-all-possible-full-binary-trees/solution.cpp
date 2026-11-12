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
    unordered_map<int,vector<TreeNode*>>dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        if(dp.find(n)!=dp.end())
            return dp[n];
        vector<TreeNode*>ans;
        if(n%2==0)
            return ans;
        if(n==1)
        {
            ans.push_back(new TreeNode(0));
            return dp[n]=ans;
        }
        for(int l=1;l<n;l+=2)
        {
            int r=n-1-l;
            vector<TreeNode*>left=allPossibleFBT(l);
            vector<TreeNode*>right=allPossibleFBT(r);
            for(auto a:left)
            {
                for(auto b:right)
                {
                    TreeNode* root=new TreeNode(0);
                    root->left=a;
                    root->right=b;
                    ans.push_back(root);
                }
            }
        }
        return dp[n]=ans;
    }
};
