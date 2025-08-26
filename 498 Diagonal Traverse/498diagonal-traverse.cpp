class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> moves = {{-1,1},{1,-1}};
        vector<vector<int>> moves2 = {{0,1}, {1,0}};
        int idx = 0;
        int i = 0, j = 0, top = 0;
        vector<int> ans(n * m);
        while (i < n && j < m) {
            while (1) {
                ans[top++] = mat[i][j];
                int I = i + moves[idx][0];
                int J = j + moves[idx][1];
                if (0 <= I && I < n && 0 <= J && J < m) {
                    i = I;
                    j = J;
                } else
                    break;
            }
            bool f = false;
            for (auto move : moves2) {
                int I = move[0] + i;
                int J = move[1] + j;
                if (0 <= I && I < n && 0 <= J && J < m) {
                    i = I;
                    j = J;
                    f = true;
                    break;
                }
            }
            if (!f)
                break;
            idx ^= 1;
            swap(moves2[0], moves2[1]);
        }
        return ans;
    }
};