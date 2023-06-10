/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let l = 0;
    let r = nums.length - 1;

    while (l <= r) {
        let m = Math.floor(l + (r - l) / 2);

        if (nums[m] === target) return m;
        
        // Pivot in left side
        if (nums[m] >= nums[0]) {
            if (target > nums[m] || target < nums[0]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        } 
        
        // Pivot in right side
        else {
            if (target < nums[m] || target >= nums[0]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }

    return -1;
};