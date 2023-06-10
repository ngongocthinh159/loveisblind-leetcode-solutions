/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    const map = new Map();


    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], map.get(nums[i]) + 1 || 1);
    }

    const sorted = [...map.entries()].sort((([k1, v1], [k2, v2]) => {
        return v2 - v1;
    }));

    return sorted.slice(0, k).map(([num, freq]) => num);
};