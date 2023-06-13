/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function(arr) {
    let curMax = Math.max(-1, arr[arr.length - 1]);
    arr[arr.length - 1] = -1;
    for (let i = arr.length - 2; i >= 0; i--) {
        const temp = arr[i];
        arr[i] = curMax;
        curMax = Math.max(curMax, temp);
    }

    return arr;
};