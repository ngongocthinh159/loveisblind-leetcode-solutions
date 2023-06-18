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
 * @return {boolean}
 */
var isValidBST = function(root) {
    // Recursion
    // let res = true;
    // let prev = null;
    // const inorderTraverse = (root) => {
    //     if (!root) return;

    //     inorderTraverse(root.left);
    //     const cur = root.val;
    //     if (prev !== null && prev >= cur) {
    //         res = false;
    //     }
    //     prev = cur;
    //     inorderTraverse(root.right);
    // }
    // inorderTraverse(root);
    // return res;

    let prev = Number.NEGATIVE_INFINITY;
    let res = true;
    var inorderIterative = (root) => {
        if (!root) return;
        const stack = [root];

        while (stack.length > 0) {
            let cur = stack[stack.length - 1];

            while (cur.left) {
                stack.push(cur.left);
                cur = cur.left;
            }

            let returnFromLeft = null;
            do {
                returnFromLeft = stack.pop();

                // Current popout value compare with prev value => If prev >= current
                // Then return false
                if (prev >= returnFromLeft.val) {
                    res = false;
                    return;
                } else prev = returnFromLeft.val;
            } while (stack.length > 0 && !returnFromLeft.right);

            if (returnFromLeft.right) stack.push(returnFromLeft.right);
        }
    };
    inorderIterative(root);

    return res;
};

