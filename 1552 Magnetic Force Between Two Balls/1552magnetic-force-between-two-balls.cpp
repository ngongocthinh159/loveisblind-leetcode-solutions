class Solution {
public:
    bool check(int x, vector<int>& position, int m) {
        int cnt = 1, prev = position[0], i = 1, n = position.size();
        while (i < n) {
            int start = i;
            while (i < n && !(position[i] - prev >= x)) {
                i++;
            }
            if (i < n) {
                cnt++;
                prev = position[i];
                i++;
            } else break;
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int l = 0, r = position[n - 1] + 1;
        while (r - l > 1) {
            int mid = l + (r - l)/2;
            if (check(mid, position, m)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};