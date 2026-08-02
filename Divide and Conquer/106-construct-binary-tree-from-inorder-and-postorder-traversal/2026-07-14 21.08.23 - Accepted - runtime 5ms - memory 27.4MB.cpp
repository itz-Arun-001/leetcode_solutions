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
    TreeNode* buildTree(vector<int>& inorder,int istart,int iend,vector<int>& postorder,int pstart,int pend,map<int,int>& imp)
    {
        if(pstart>pend||istart>iend) return NULL;
        TreeNode* root=new TreeNode(postorder[pend]);
        int iroot=imp[root->val];
        int nleft=iroot-istart;
        root->left=buildTree(inorder,istart,iroot-1,postorder,pstart,pstart+nleft-1,imp);
        root->right=buildTree(inorder,iroot+1,iend,postorder,pstart+nleft,pend-1,imp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>imp;
        for(int i=0;i<inorder.size();i++)
        {
            imp[inorder[i]]=i;
        }
        TreeNode* root=buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,imp);
        return root;
        
    }
};;