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
 * @return {number[][]}
 */
var levelOrder = function(root) {
    const res = [];
    dfs(root, 1, res);
    return res;
};

const dfs = (root, height, res) => {
    if (!root) return;
    if (height > res.length) res[height - 1] = [];
    res[height - 1].push(root.val);
    dfs(root.left, height + 1, res);
    dfs(root.right, height + 1, res);
}