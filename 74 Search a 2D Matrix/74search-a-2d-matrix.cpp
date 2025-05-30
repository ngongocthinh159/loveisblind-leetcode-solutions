class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int N = n*m;
        int l = -1, r = N;
        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            int i = mid/m;
            int j = mid - i*m;
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) 
                l = mid;
            else
                r = mid;
        } 
        return false;
    }
};