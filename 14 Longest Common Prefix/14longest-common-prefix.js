/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 1) return strs[0];
    let prefix = strs[0];
    let maxLength = Number.MAX_VALUE;

    for (let i = 1; i < strs.length; i++) {
        const str = strs[i];
        
        let j = 0;
        while (j < Math.min(prefix.length, maxLength) && j < str.length && prefix[j] === str[j]) {
            j++;
        }

        maxLength = j;
    }

    return prefix.slice(0, maxLength);
};