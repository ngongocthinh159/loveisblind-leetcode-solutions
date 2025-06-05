class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        int n = stones.size();
        unordered_map<int,int> posToIdx;
        for (int i = 0; i < n; i++) {
            posToIdx[stones[i]] = i;
        }
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        dp[1][0] = true;
        for (int i = 1; i < n - 1; i++) {
            for (int k = 0; k < i; k++) if (dp[i][k]) {
                int lastDist = stones[i] - stones[k];
                for (int j = lastDist - 1; j <= lastDist + 1; j++) if (j) {
                    if (posToIdx.count(stones[i] + j)) {
                        dp[posToIdx[stones[i] + j]][i] = 1;
                    }
                }
            }
        }
        bool ans = false;
        for (int k = 0; k < n - 1; k++) ans = ans | dp[n - 1][k];
        return ans;
    }
};