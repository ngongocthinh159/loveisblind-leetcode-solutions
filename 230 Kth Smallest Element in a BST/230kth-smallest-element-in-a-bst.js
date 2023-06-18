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
 * @param {number} k
 * @return {number}
 */

var kthSmallest = function(root, k) {
    const stack = [root];
    let count = 0;
    const set = new Set();

    while (stack.length > 0) {
        const cur = stack[stack.length - 1];

        if (cur.left && !set.has(cur.left)) {
            stack.push(cur.left);
        } else {
            const popout = stack.pop();
            set.add(popout);
            count++;
            if (count === k) return popout.val;

            if (popout.right && !set.has(popout.right)) {
                stack.push(popout.right);
            }
        }
    }
};

