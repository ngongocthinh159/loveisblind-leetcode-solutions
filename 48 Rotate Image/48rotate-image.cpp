class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j >= i) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = tmp;   
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j < (n + 1)/2) {
                    int tmp = matrix[i][j];
                    matrix[i][j] = matrix[i][n - 1 - j];
                    matrix[i][n - 1 - j] = tmp;
                }                
            }
        }
    }
};