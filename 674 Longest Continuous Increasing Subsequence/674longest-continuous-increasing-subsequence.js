/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function(nums) {
    let i = 0;
    let j = 1;
    let max = 1;

    while (j < nums.length) {
        
        let count = 1;
        while (j < nums.length && nums[j] > nums[j - 1]) {
            count++;
            j++;
            if (max < count) max = count;
        }

        i = j;
        j++;
    }

    return max;
};