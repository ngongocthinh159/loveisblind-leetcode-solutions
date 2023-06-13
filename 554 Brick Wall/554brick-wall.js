/**
 * @param {number[][]} wall
 * @return {number}
 */
var leastBricks = function(wall) {
    const map = new Map();
    let maxFreq = Number.MIN_VALUE;
    let maxFreqSum = -1;

    for (let i = 0; i < wall.length; i++) {
        const bricks = wall[i];
        let sum = 0;
        for (let j = 0; j < bricks.length - 1; j++) {
            sum += bricks[j];
            if (!map.has(sum)) map.set(sum, 1);
            else map.set(sum, map.get(sum) + 1);
            
            const temp = map.get(sum);
            if (maxFreq < temp) {
                maxFreq = temp;
                maxFreqSum = sum;
            }
        }
    }

    if (maxFreqSum === -1) return wall.length;

    return wall.length - map.get(maxFreqSum);
};