class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int mn = 1e8;
        int cnt = 0;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i< n;i++) {
            for (int j = 0; j < m; j++) {
                mn = min(mn, abs(matrix[i][j]));
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) cnt++;
            }
        }
        if (cnt&1) sum -= 2*mn;
        return sum;
    }
};