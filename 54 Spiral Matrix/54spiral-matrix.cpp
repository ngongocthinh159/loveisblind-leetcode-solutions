class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int startX = 0, endX = n - 1, startY = 0, endY = m - 1;
        vector<int> ans;
        while (startX <= endX && startY <= endY) {
            for (int i = startY; i <= endY; i++)
                ans.push_back(matrix[startX][i]);
            for (int i = startX + 1; i <= endX; i++)
                ans.push_back(matrix[i][endY]);
            if (startX < endX) {
                for (int i = endY-1; i >= startY; i--)
                    ans.push_back(matrix[endX][i]);
            }
            if (startY < endY) {
                for (int i = endX-1; i >= startX + 1; i--)
                    ans.push_back(matrix[i][startY]);
            }
            startX++; endX--; startY++; endY--;
        }

        return ans;
    }
};