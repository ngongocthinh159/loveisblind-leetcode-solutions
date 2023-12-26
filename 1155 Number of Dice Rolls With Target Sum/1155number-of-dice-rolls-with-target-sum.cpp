class Solution {
public:
    int mod = 1e9 + 7;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> cur(target + 1);
        vector<int> next(target + 1, 0);
        next[target] = 1;
        for (int i = n - 1; i >= 0; i--) {
            fill(cur.begin(), cur.end(), 0);
            for (int j = target; j >= 0; j--) {
                for (int choose = 1; choose <= k; choose++) {
                    if (choose + j <= target) cur[j] = (cur[j] + next[choose + j])%mod;
                }
            }
            next = cur;
        }
        return cur[0];
    }
};