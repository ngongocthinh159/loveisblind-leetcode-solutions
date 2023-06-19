/**
 * @param {number[]} gain
 * @return {number}
 */
var largestAltitude = function(gain) {
    const altitude = new Array(gain.length + 1).fill(0);
    let max = 0;
    for (let i = 1; i < gain.length + 1; i++) {
        altitude[i] = altitude[i - 1] + gain[i - 1];
        max = Math.max(max, altitude[i]);
    }

    return max;
};