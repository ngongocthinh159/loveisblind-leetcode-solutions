/**
 * @param {string} s
 * @return {number}
 */
var minLength = function(s) {
    const stack = [];

    let i = 0;
    while (i < s.length) {
        if (stack.length !== 0 && ((stack[stack.length - 1] === 'A' && s[i] === 'B') || 
        (stack[stack.length - 1] === 'C' && s[i] === 'D'))) {
            stack.pop();
        } else {
            stack.push(s[i]);
        }

        i++;
    }

    return stack.length;
};