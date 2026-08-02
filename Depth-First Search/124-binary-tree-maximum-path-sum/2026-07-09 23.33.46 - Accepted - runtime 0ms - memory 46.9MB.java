/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int path(TreeNode node,int[] maxsum)
    {
        if(node==null) return 0;
        int ls=Math.max(0,path(node.left,maxsum));
        int rs=Math.max(0,path(node.right,maxsum));
        maxsum[0]=Math.max(maxsum[0],ls+rs+node.val);
        return Math.max(ls,rs)+node.val;

    }
    public int maxPathSum(TreeNode root) {
        int[] maxsum=new int[1];
        maxsum[0]=Integer.MIN_VALUE;
        path(root,maxsum);
        return maxsum[0];
        
    }
}