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
    public TreeNode deleteNode(TreeNode root, int val) {
        if (root == null) return null;
        
        if (val == root.val) {
            // Case 1: no subtree
            if (root.left == null && root.right == null) {
                return null;
            }

            // Case 2: 1 subtree
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;

            // Case 3: 2 subtrees
            TreeNode minOfRight = root.right;
            while (minOfRight.left != null) {
                minOfRight = minOfRight.left;
            }
            root.val = minOfRight.val;
            root.right = deleteNode(root.right, root.val);
        }
        
        if (val < root.val) {
            root.left = deleteNode(root.left, val);
        } else if (val > root.val) {
            root.right = deleteNode(root.right, val);
        }
        
        return root;
    }
}