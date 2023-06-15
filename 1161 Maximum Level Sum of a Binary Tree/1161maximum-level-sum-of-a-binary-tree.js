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
var maxLevelSum = function(root) {
    const queue = [];
    queue.push(root);
    let firstMaxLevel = 0;
    let maxSum = Number.NEGATIVE_INFINITY;
    let curLevel = 0;

    while (queue.length > 0) {
        curLevel++;
        let levelLength = queue.length;
        let levelSum = 0;

        for (let i = 0; i < levelLength; i++) {
            const cur = queue.pop();
            levelSum += cur.val;
            if (cur.left) queue.unshift(cur.left);
            if (cur.right) queue.unshift(cur.right);
        }
        
        if (maxSum < levelSum) {
            maxSum = levelSum;
            firstMaxLevel = curLevel;
        }
    }

    return firstMaxLevel;
};