/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solve = function(board) {
    let count = 0;  
    const visited = new Array(board.length).fill().map(row => new Array(board[0].length).fill(false));
    
    for (let i = 0; i < board.length; i++) {
        for (let j = 0; j < board[0].length; j++) {
            if (!visited[i][j] && board[i][j] === 'O') {
                const shouldCapture = [true];
                const islandPos = [];

                // Push the first pos
                visited[i][j] = true;
                islandPos.push([i, j]);
                if (i === 0 || i === board.length - 1 || j === 0 || j === board[0].length - 1) shouldCapture[0] = false;
                exploreFromPos([i, j], board, visited, shouldCapture, islandPos);

                count++;
                if (shouldCapture[0]) {
                    capture(islandPos, board);
                }
            }
        }
    }


    return board;
};

var capture = (islandPos, grid) => {
    islandPos.forEach(pos => grid[pos[0]][pos[1]] = 'X');
}

var exploreFromPos = (pos, grid, visited, shouldCapture, islandPos) => {

    const move = [[0, 1], [1, 0], [0, -1], [-1, 0]];

    for (let i = 0; i < move.length; i++) {
        const [dx, dy] = move[i];
        const [newX, newY] = [dx + pos[0], dy + pos[1]];

        if (0 <= newX && newX < grid.length && 0 <= newY && newY < grid[0].length && !visited[newX][newY] && grid[newX][newY] === 'O') {
            visited[newX][newY] = true;
            islandPos.push([newX, newY]);
            if (newX === 0 || newX === grid.length - 1 || newY === 0 || newY === grid[0].length - 1) shouldCapture[0] = false;

            exploreFromPos([newX, newY], grid, visited, shouldCapture, islandPos);
        }
    }
}