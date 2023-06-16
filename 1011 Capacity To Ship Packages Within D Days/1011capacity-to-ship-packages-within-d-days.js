/**
 * @param {number[]} weights
 * @param {number} days
 * @return {number}
 */
var shipWithinDays = function(weights, days) {
  let l = 0;
  let sum = 0;
  weights.forEach(weight => {
    sum += weight;
    if (l < weight) {
      l = weight;
    }
  })
  
  let r = sum;
  
  // Start searching for valid capacity
  while (l <= r) {
    const m = Math.floor(l + (r - l) / 2);
    const neededDays = calculateNeededDays(weights, m);

    if (neededDays > days) { // If the needed days > days => Capacity is too small => Need to increase the capacity
      l = m + 1;
    } else {
      r = m - 1;
    }
  }

  return l;
};

var calculateNeededDays = (weights, capacity) => {
  let j = 0;
  let count = 0;

  while (j < weights.length) {
    let sum = 0;
    while (j < weights.length && sum + weights[j] <= capacity) {
      sum += weights[j];
      j++;
    }

    count++;
  }

  return count;
}