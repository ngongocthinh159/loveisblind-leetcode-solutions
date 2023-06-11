/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
    let l = 0;
    let r = nums.length - 1;
    let minValue = Number.MAX_VALUE;
    
    while (l <= r) {
        let m = Math.floor(l + (r - l) / 2);

        if (minValue > nums[m]) {
            minValue = nums[m];
        }

        if (nums[l] === nums[r]) {
            r--;
            continue;
        }
        
        // Pivot in left side
        if (nums[m] >= nums[l] && nums[l] > nums[r]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return minValue;
};