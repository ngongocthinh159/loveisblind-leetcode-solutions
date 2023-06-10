/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    let res = 0;
    const set = new Set();
    const visited = new Set();

    for (let i = 0; i < nums.length; i++) {
        if (!set.has(nums[i])) set.add(nums[i]);
    }

    // Traverse up and down of a current num to count the longest sequence
    for (let i = 0; i < nums.length; i++) {
        const curNum = nums[i];

        if (visited.has(curNum)) continue;

        visited.add(curNum);
        let count = 1;
        let nextNum = curNum;
        let prevNum = curNum;
        while (set.has(++nextNum)) {
            count++;
            visited.add(nextNum);
        }
        while (set.has(--prevNum)) {
            count++;
            visited.add(prevNum);
        }

        if (res < count) res = count;
    }

    return res;
};