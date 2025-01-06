/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    vector<int> dp;
    int get(int idx, MountainArray &arr) {
        if (dp[idx] != -1) return dp[idx];
        return dp[idx] = arr.get(idx);
    }
    int bin_search(int l, int r, int mode, int target, MountainArray &arr) {
        l--, r++;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            int cur = get(m, arr);
            if (cur == target) return m;
            if (mode == 1) {
                if (cur < target)
                    l = m;
                else
                    r = m;
            } else {
                if (cur > target)
                    l = m;
                else
                    r = m;
            }
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &arr) {
        int n = arr.length();
        dp = vector<int>(n, -1);
        int l = 0, r = n;
        int mount_idx = -1;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            int cur = get(m, arr);
            int prev = get(m - 1, arr);
            if (cur > prev)
                l = m;
            else
                r = m;
        }

        if (l == 0) {
            int val0 = get(0, arr);
            int val1 = get(1, arr);
            if (val0 < val1) mount_idx = 1;
            else mount_idx = 0;
        } else {
            mount_idx = l;
        }
        int res1 = bin_search(0, mount_idx, 1, target, arr);
        if (res1 != -1) return res1;
        return bin_search(mount_idx, n - 1, -1, target, arr);
    }
};