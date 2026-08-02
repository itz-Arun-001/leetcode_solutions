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
    TreeNode* buildTree(vector<int>& preorder,int pstart,int pend,vector<int>& inorder,int istart,int iend,map<int,int>& imp)
    {
        if(pstart>pend||istart>iend) return NULL;
        TreeNode* root=new TreeNode(preorder[pstart]);
        int iroot=imp[root->val];
        int nleft=iroot-istart;
        root->left=buildTree(preorder,pstart+1,pstart+nleft,inorder,istart,iroot-1,imp);
        root->right=buildTree(preorder,pstart+nleft+1,pend,inorder,iroot+1,iend,imp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>imp;
        for(int i=0;i<inorder.size();i++)
        {
            imp[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,imp);
        return root;
        
    }
};