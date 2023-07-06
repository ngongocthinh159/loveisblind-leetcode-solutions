class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n));
        int startX = 0, endX = n - 1, startY = 0, endY = n - 1, cnt = 1;
        while (startX <= endX && startY <= endY) {
            for (int i = startY; i <= endY; i++) {
                matrix[startX][i] = cnt; cnt++;
            }
            for (int i = startX + 1; i <= endX; i++) {
                matrix[i][endY] = cnt; cnt++; 
            }
            if (startX < endX) {
                for (int i = endY-1; i >= startY; i--) {
                    matrix[endX][i] = cnt; cnt++;
                }
            }
            if (startY < endY) {
                for (int i = endX-1; i >= startX + 1; i--) {
                    matrix[i][startY] = cnt; cnt++;
                }
            }
            startX++; endX--; startY++; endY--;
        }
        
        return matrix;
    }
};