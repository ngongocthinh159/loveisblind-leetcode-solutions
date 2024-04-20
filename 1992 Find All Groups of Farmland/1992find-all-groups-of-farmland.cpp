class Solution {
public:
    vector<vector<int>> moves1 = {{1,0}, {0,1}};
    vector<vector<int>> moves2 = {{-1,0}, {0,-1}};

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> res;
        int n = land.size();
        int m = land[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && isStart(i, j, land)) {
                    int I = i;
                    int J = j;
                    for (int k = 0; k < 2; k++) {
                        while (0 <= I && I < n && 0 <= J && J < m && land[I][J] == 1) {
                            I = I + moves1[k][0];
                            J = J + moves1[k][1];
                        }
                        if (k == 0) I--;
                        if (k == 1) J--;
                    }
                    res.push_back({i,j,I,J});
                }
            }
        }
        return res;
    }
    bool isStart(int i, int j, vector<vector<int>>& land) {
        for (int k = 0; k < 2; k++) {
            int I = i + moves2[k][0];
            int J = j + moves2[k][1];
            if (0 <= I && I < land.size() && 0 <= J && J < land[0].size() && land[I][J] == 1) return false;
        }
        return true;
    }
};