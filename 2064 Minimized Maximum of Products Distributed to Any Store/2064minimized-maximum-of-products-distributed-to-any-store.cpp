class Solution {
public:
    bool check(int x, int n, vector<int> &quantities) {
        int cnt = 0;
        for (int i = 0; i < quantities.size(); i++) {
            cnt += (quantities[i] + x - 1)/x;
        }
        return cnt <= n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l = 0, r = *max_element(quantities.begin(), quantities.end()) + 1;
        while (r - l > 1) {
            int m = l + (r - l)/2;
            if (check(m, n, quantities)) {
                r = m;
            } else {
                l = m;
            }
        }
        return r;
    }
};