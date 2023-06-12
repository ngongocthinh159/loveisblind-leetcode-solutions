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
 * @return {TreeNode}
 */
var invertTree = function(root) {
    recursive(root);
    return root;
};

var recursive = function (root) {
    if (!root) return;
    recursive(root.left);
    recursive(root.right);

    let t = root.left;
    root.left = root.right;
    root.right = t;
}