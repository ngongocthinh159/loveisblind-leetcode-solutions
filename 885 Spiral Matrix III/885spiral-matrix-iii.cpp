class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int last = rows*cols;
        int cnt = 0;
        int startX = rStart, endX = rStart + 1, startY = cStart - 1, endY = cStart + 1;
        vector<vector<int>> ans;
        while (true) {
            for (int i = startY + 1; i <= endY; i++) {
                if (0 <= startX && startX < rows && 0 <= i && i < cols) {
                    ans.push_back({startX, i}); cnt++;
                    if (cnt == rows*cols) return ans;
                }
            }
            for (int i = startX + 1; i <= endX; i++) {
                if (0 <= i && i < rows && 0 <= endY && endY < cols) {
                    ans.push_back({i, endY}); cnt++;
                    if (cnt == rows*cols) return ans;
                }
            }
            for (int i = endY - 1; i >= startY; i--) {
                if (0 <= endX && endX < rows && 0 <= i && i < cols) {
                    ans.push_back({endX, i}); cnt++;
                    if (cnt == rows*cols) return ans;
                }
            }
            for (int i = endX - 1; i >= startX; i--) {
                if (0 <= i && i < rows && 0 <= startY && startY < cols) {
                    ans.push_back({i, startY}); cnt++;
                    if (cnt == rows*cols) return ans;
                }
            }
            startX--; endX++; startY--; endY++;
        }
    }
};