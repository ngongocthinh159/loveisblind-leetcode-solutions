/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if (digits.length === 0) return [];
    const letters = [];
    const res = [];
    letters[2] = ['a', 'b', 'c'];
    letters[3] = ['d', 'e', 'f'];
    letters[4] = ['g', 'h', 'i'];
    letters[5] = ['j', 'k', 'l'];
    letters[6] = ['m', 'n', 'o'];
    letters[7] = ['p', 'q', 'r', 's'];
    letters[8] = ['t', 'u', 'v'];
    letters[9] = ['w', 'x', 'y', 'z'];

    generatePermutations(digits, letters, [], res);
    return res;
};

var generatePermutations = (digits, letters, curPath, res) => {
    if (curPath.length === digits.length) {
        res.push(curPath.join(''));
        return;
    }

    const digit = parseInt(digits[curPath.length]);
    for (let j = 0; j < letters[digit].length; j++) {
        curPath.push(letters[digit][j]);
        generatePermutations(digits, letters, curPath, res);
        curPath.pop();
    }
}