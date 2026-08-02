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
     TreeNode* prev=NULL;
    void flatten(TreeNode* node) {
        if(node==NULL) return;
        if(node->right) flatten(node->right);
        if(node->left)  flatten(node->left);
        node->right=prev;
        node->left=nullptr;
        prev=node;
       
        
    }
};*/
class Solution {
public:
     //TreeNode* prev=NULL;
    void flatten(TreeNode* node) {
        if (node== nullptr) return;
        stack<TreeNode* >st;
        st.push(node);
        while(!st.empty())
        {
            TreeNode* curr=st.top();
            st.pop();
            
            if(curr->right) st.push(curr->right);
            if(curr->left)  st.push(curr->left);
            if(!st.empty()){
                curr->right=st.top();
            }
            curr->left=NULL;
        }
    }
};