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
 * @return {number[]}
 */
var postorderTraversal = function(root) {
    if (!root) return [];
    
    // Post-order traversal left first then right = Reverse(Pre-order traversal right first then left)
    const stack = [root];
    const res = [];

    while (stack.length > 0) {
        const cur = stack.pop();
        res.unshift(cur.val);

        if (cur.left) stack.push(cur.left);
        if (cur.right) stack.push(cur.right);
    }

    return res;
};