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
    vector<vector<int>>ans;
    void help(TreeNode* root,int& t,int& curr,vector<int>& temp)
    {
        if(root==NULL) return;
        curr+=root->val;
        temp.push_back(root->val);
        if(root->right==NULL&&root->left==NULL&&curr==t)
        {
            ans.push_back(temp);
            //return;
        }
       /// if(curr>t||root==NULL) return;
        //TreeNode* dummy=root;
        help(root->left,t,curr,temp);
        help(root->right,t,curr,temp);
        curr-=root->val;
       // root=dummy;
        temp.pop_back();
        

    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int>temp;
         int cur=0;
        help(root,target,cur,temp);
        return ans;
    }
};
