class Solution {
public:
    bool check(int x, vector<int>& bloomDay, int m, int k) {
        int i = 0, n = bloomDay.size();
        int cnt, bouquet = 0;
        while (i < n) {
            if (bloomDay[i] <= x) {
                cnt = 1;
                while (i + 1 < n && bloomDay[i + 1] <= x && cnt < k) {
                    i++;
                    cnt++;
                    if (cnt >= k) break;
                }

                if (cnt >= k) bouquet++;
            }

            i++;
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mx = *max_element(bloomDay.begin(), bloomDay.end());
        int l = 0, r = mx + 1;
        while (r - l > 1) {
            int mid = l + (r - l)/2;

            if (check(mid, bloomDay, m, k)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (r == mx + 1) return -1;
        return r;
    }
};