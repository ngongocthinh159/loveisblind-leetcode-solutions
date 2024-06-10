class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected(heights.begin(), heights.end());
        __sort(expected, 0, heights.size() - 1);
        int ans = 0;
        for (int i = 0; i < (int) heights.size(); i++) {
            if (expected[i] != heights[i]) ans++;
        }
        return ans;
    }
    void __sort(vector<int> &v, int l, int r) {
        if (r - l + 1 == 1) return;
        int m = l + (r - l)/2;
        __sort(v, l, m);
        __sort(v, m + 1, r);
        merge(v, l, m, m + 1, r);
    }
    void merge(vector<int> &v, int l1, int r1, int l2, int r2) {
        vector<int> cur;
        int i = l1;
        int j = l2;
        while (i <= r1 && j <= r2) {
            if (v[i] <= v[j]) cur.push_back(v[i++]);
            else cur.push_back(v[j++]);
        }
        while (i <= r1) cur.push_back(v[i++]);
        while (j <= r2) cur.push_back(v[j++]);
        for (int k = l1; k <= r2; k++) {
            v[k] = cur[k - l1];
        }
    }
};