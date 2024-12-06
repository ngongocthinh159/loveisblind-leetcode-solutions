#define ll long long
class Solution {
public:
    int maxCount(vector<int>& ban, int n, int maxSum) {
        vector<bool> visited(n + 1);
        for (auto x : ban) if (x <= n) visited[x] = true;
        int ans = 0;
        for (int i = 1; i <= n && maxSum >= i; i++) {
            if (!visited[i]) {
                ans++;
                maxSum -= i;
            }
        }
        return ans;
    }
};