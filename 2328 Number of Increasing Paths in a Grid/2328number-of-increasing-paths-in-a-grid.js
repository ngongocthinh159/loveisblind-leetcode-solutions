/**
 * @param {number[][]} grid
 * @return {number}
 */
var countPaths = function(grid) {
    let count = 0;
    let mod = Math.pow(10, 9) + 7;
    const paths = new Map();
    const dp = new Array(grid.length).fill().map(row => new Array(grid[0].length).fill(0));

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (dp[i][j] === 0) dp[i][j] = pathsAtPos(grid, [i, j], dp);
            count += dp[i][j] % mod;
        }
    }

    // console.log(dp);
    return count % mod;
};

var pathsAtPos = (grid, pos, dp) => {
    if (dp[pos[0]][pos[1]] !== 0) return dp[pos[0]][pos[1]];

    const directions = [[-1, 0], [0, -1], [1, 0], [0, 1]];
    let atLeastOneMove = false;
    let mod = Math.pow(10, 9) + 7;

    for (let i = 0; i < directions.length; i++) {
        const [dx, dy] = directions[i];
        const [curX, curY] = pos;
        const [newX, newY] = [curX + dx, curY + dy];

        if (0 <= newX && newX < grid.length && 0 <= newY && newY < grid[0].length && grid[newX][newY] > grid[curX][curY]) {
            if (dp[curX][curY] === 0) dp[curX][curY]++;
            dp[curX][curY] += pathsAtPos(grid, [newX, newY], dp) % mod;
            atLeastOneMove = true;
        }
    }

    if (!atLeastOneMove) {
        return dp[pos[0]][pos[1]] = 1;
    } else{
        return dp[pos[0]][pos[1]];
    }
};