class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for (int i= 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1) {
                    row[i]++; col[j]++;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};