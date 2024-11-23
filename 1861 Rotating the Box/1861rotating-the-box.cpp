class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> mat(m, vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            int nearest = m;
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    int move = (nearest - 1) - j;
                    box[i][j] = '.';
                    box[i][j + move] = '#';
                    nearest = j + move;
                } else if (box[i][j] == '*') {
                    nearest = j;
                }
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << box[i][j];
        //     }
        //     cout << "\n";
        // }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mat[j][i] = box[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0, k = n - 1; j < k; j++, k--) {
                char tmp = mat[i][j];
                mat[i][j] = mat[i][k];
                mat[i][k] = tmp;
            }
        }
        return mat;
    }
};