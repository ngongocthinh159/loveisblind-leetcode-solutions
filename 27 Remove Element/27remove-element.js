/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    
    let l = 0;
    let r = nums.length - 1;
    let count = 0;

    while (l <= r) {
        if (nums[l] === val) {
            const temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            if (nums[l] !== nums[r]) l++;
            r--;
            count++;
        } else {
            l++;
        }
    }

    return nums.length - count;
};