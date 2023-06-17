/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    // Brute force solution
    // let i = 0;

    // while (i < haystack.length) {
    //     let cur = i;
    //     let j = 0;

    //     while (cur < haystack.length && j < needle.length && haystack[cur] === needle[j]) {
    //         cur++;
    //         j++;
    //     }

    //     if (j === needle.length) return cur - needle.length;

    //     i++;
    // }

    // return -1;



    // KMP solution
    return KMP(haystack, needle);
};

var KMP = (string, pattern) => {
  const LPS = getLPS(pattern); // Build LPS first for each character in pattern
  let i = 0;
  let j = 0;

  while (i < string.length) {
    if (string[i] === pattern[j]) {
      i++;
      j++;
    } else {
      if (j === 0) i++;
      else {
        j = LPS[j - 1];
      }
    }

    if (j === pattern.length) return i - pattern.length;
  }

  return -1;
}

var getLPS = (pattern) => {
  const LPS = new Array(pattern.length).fill(0);

  let i = 1;
  let prevLength = 0;

  while (i < pattern.length) {
    if (pattern[i] === pattern[prevLength]) {
      LPS[i] = prevLength + 1;
      prevLength++;
      i++;
    } else {
      if (prevLength === 0) {
        LPS[i] = 0;
        i++;
      } else {
        prevLength = LPS[prevLength - 1];
      }
    }
  }

  return LPS;
};