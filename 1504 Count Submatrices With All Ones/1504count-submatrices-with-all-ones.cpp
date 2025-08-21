class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> h(m);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> nh(m);
            for (int j = 0; j < m; j++) {
                nh[j] = mat[i][j] == 1 ? 1 + h[j] : 0;
                int H = nh[j];
                for (int k = j; k >= 0; k--) {
                    H = min(H, nh[k]);
                    ans += H;
                }
            }
            swap(h, nh);
        }
        return ans;
    }
};