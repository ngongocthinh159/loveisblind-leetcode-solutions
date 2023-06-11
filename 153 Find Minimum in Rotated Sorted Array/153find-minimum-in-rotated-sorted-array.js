/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let l = 0;
    let r = nums.length - 1;
    let min = Number.MAX_VALUE;

    while (l <= r) {
        let m = Math.floor(l + (r - l) / 2);

        if (min > nums[m]) min = nums[m];
        
        // Pivot in left side
        if (nums[m] >= nums[0] && nums[l] > nums[r]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return min;
};