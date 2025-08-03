class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size(), ans = 0, window = 0;
        // cost function
        // if r < startPos: startPos - l
        // if l > startPos: r - startPos
        // else:
            // r - startPos + r - l
            // startPos - l + r - l
            // r - l + min(r - startPos, startPos - l)
        auto cost = [&](int l, int r) {
            if (fruits[r][0] < startPos) return startPos - fruits[l][0];
            if (fruits[l][0] > startPos) return fruits[r][0] - startPos;
            return fruits[r][0] - fruits[l][0] + min(fruits[r][0] - startPos, startPos - fruits[l][0]);
        };
        for (int r = 0, l = 0; r < n; r++) {
            window += fruits[r][1];
            while (l <= r && cost(l, r) > k) {
                window -= fruits[l][1];
                l++;
            }
            ans = max(ans, window);
        }
        return ans;

    }
};