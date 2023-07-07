class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int ans = -1;
        vector<int> dp(arr.size(), -1);
        for (int k = 0; k < arr.size(); k++) {
            ans = max(ans, dfs(arr, d, k, dp));
        }

        return ans;
    }

    int dfs(vector<int>& arr, int d, int curIndex, vector<int>& dp) {
        if (dp[curIndex] != -1) return dp[curIndex];

        int maxRight = 0, maxLeft = 0;

        int startIndex = curIndex + 1, endIndex = curIndex + d;
        for (int i = startIndex; i <= endIndex && i < arr.size() && arr[curIndex] > arr[i]; i++) {
            maxRight = max(maxRight, dfs(arr, d, i, dp));
        }
        
        startIndex = curIndex - 1; endIndex = curIndex - d;
        for (int i = startIndex; i >= endIndex && i >= 0 && arr[curIndex] > arr[i]; i--) {
            maxLeft = max(maxLeft, dfs(arr, d, i, dp));
        }

        return dp[curIndex] = max(1 + maxRight, 1 + maxLeft);
    }
};