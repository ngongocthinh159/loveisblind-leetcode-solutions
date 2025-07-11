class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int pref_mx = -1;
        int ans = 0;
        vector<int> surf(n + 2, 1e9);
        for (int i = n - 1; i >= 0; i--) {
            surf[i + 1] = min(surf[i + 2], arr[i]);
        }
        for (int i = 0; i < n; i++) {
            pref_mx = max(pref_mx, arr[i]);
            if (pref_mx <= surf[i + 2]) {
                ans++;
                pref_mx = -1;
            }
        }
        return ans;
    }
};