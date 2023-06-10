/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];

    for (let i = 0; i < s.length; i++) {
        const curChar = s[i];

        if (curChar === '(' || curChar === '{' || curChar === '[') {
            stack.push(curChar);
        } else {
            const topChar = stack[stack.length - 1];
            switch (curChar) {
                case ')':
                    if (topChar === '(') stack.pop();
                    else return false;
                    break;
                case '}':
                    if (topChar === '{') stack.pop();
                    else return false;
                    break;
                case ']':
                    if (topChar === '[') stack.pop();
                    else return false;
                    break;
            }
        }
    }

    return stack.length === 0;
};