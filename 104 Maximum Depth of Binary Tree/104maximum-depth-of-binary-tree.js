/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var maxDepth = function(root) {
    let max = -1;
    const dfs = (root, depth) => {
        if (!root) {
            max = Math.max(max, depth - 1);
            return;
        }

        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }
    dfs(root, 1);

    return max;
};