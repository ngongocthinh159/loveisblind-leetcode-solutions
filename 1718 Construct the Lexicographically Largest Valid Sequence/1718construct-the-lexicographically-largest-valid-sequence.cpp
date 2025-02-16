class Solution {
public:
    vector<int> res;
    bool dfs(int mask, int i, int n) {
        if (i == 2*n - 1) 
            return true;
        if (res[i] != -1) 
            return dfs(mask, i + 1, n);

        for (int j = n; j >= 1; j--) {
            if (!((mask >> (j - 1)) & 1)) {
                if (j == 1) {
                    res[i] = j;
                    if (dfs(mask | (1 << (j - 1)), i + 1, n)) 
                        return true;
                    res[i] = -1;
                } else if (i + j < 2*n - 1 && res[i + j] == -1) {
                    res[i] = j;
                    res[i + j] = j;
                    if (dfs(mask | (1 << (j - 1)), i + 1, n)) 
                        return true;
                    res[i] = -1;
                    res[i + j] = -1;
                }
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        res.assign(2*n - 1, -1);
        dfs(0, 0, n);
        return res;
    }
};