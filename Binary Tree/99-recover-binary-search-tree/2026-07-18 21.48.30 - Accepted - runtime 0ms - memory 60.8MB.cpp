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
 *//*
class Solution {
    private:
     TreeNode* first;
     TreeNode* middle;
     TreeNode* last;
     TreeNode* prev;
     private:
        void inorder(TreeNode* root)
        {
            if(root==nullptr) return;
            inorder(root->left);
            if(prev!=NULL&&root->val<prev->val){
                if(first==nullptr){
                    first=prev;
                    middle=root;
                }
                else last=root;
            }
            prev=root;
            inorder(root->right);
        }
public:
    void recoverTree(TreeNode* root) {
        first=nullptr;
        last=nullptr;
        middle=nullptr;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        if(first&&last) swap(first->val,last->val);
        else if(first&&middle) swap(first->val,middle->val);
        
    }
};
*/

class Solution {
    private:
     TreeNode* first;
     TreeNode* middle;
     TreeNode* last;
     TreeNode* prev;
     private:
      void findviolation(TreeNode* curr){
        if(prev!=nullptr&&curr->val<prev->val)
        {
            if(first==nullptr) {
                first=prev;
                middle=curr;
            }
            else {
                last=curr;
            }
        }
        prev=curr;
      }
public:
    void recoverTree(TreeNode* root) {
        first=nullptr;
        last=nullptr;
        middle=nullptr;
        prev=nullptr;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==nullptr)
            {
                findviolation(curr);
                curr=curr->right;
            }
            else{
                TreeNode* prevnode=curr->left;;
                while(prevnode->right&&prevnode->right!=curr)
                    prevnode=prevnode->right;
                if(prevnode->right==nullptr)
                {
                    prevnode->right=curr;
                    curr=curr->left;
                }
                else{
                    prevnode->right=nullptr;
                    findviolation(curr);
                    curr=curr->right;
                }
            }
        }
         if(first&&last) swap(first->val,last->val);
        else if(first&&middle) swap(first->val,middle->val);
    }
};
