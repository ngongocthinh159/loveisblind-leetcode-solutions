#define ll long long
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n + 1), surf(n + 2); 
        for (int i = 0; i < n; i++) {
            pref[i + 1] = max(arr[i], pref[i] + arr[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            surf[i + 1] = max(arr[i], surf[i + 2] + arr[i]);
        }
        int ans = -1e9;
        for (int i = 0; i < n; i++) {
            ans = max(ans, pref[i + 1]);
            if (i > 0 && i < n - 1) {
                ans = max(ans, pref[i] + surf[i + 2]);
            }
        }
        return ans;
    }
};