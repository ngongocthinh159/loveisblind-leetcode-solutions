class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0, ans = INT_MAX, n = blocks.size();
        for (int r = 0; r < k; r++) {
            if (blocks[r] == 'W') cnt++;
        }
        ans = min(ans, cnt);
        for (int r = k; r < n; r++) {
            if (blocks[r] == 'W') cnt++;
            if (blocks[r - k] == 'W') cnt--;
            ans = min(ans, cnt);
        }
        return ans;
    }
};