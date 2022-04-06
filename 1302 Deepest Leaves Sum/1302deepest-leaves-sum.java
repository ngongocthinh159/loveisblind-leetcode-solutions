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
    public int deepestLeavesSum(TreeNode root) {
        if (root == null) return 0;
        int[] sum = new int[2];
        sum[0] = 0;
        sum[1] = 0;
        
        DFS(root, 0, sum);
        return sum[1];
    }
    
    public void DFS(TreeNode root, int height, int[] sum) {
        if (root.left == null && root.right == null) {
            if (sum[0] == height) sum[1] += root.val;
            if (sum[0] < height) {
                sum[1] = root.val;
                sum[0] = height;
            }
        }
        
        if (root.left != null) {
            DFS(root.left, height + 1, sum);
        }
        
        if (root.right != null) {
            DFS(root.right, height + 1, sum);
        }
    }
}