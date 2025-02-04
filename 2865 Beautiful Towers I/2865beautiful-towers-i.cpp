class Solution {
public:
    void fill(vector<int> &heights, vector<long long> &L) {
        int n = heights.size();
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (st.size() && heights[st.back()] >= heights[i]) st.pop_back();
            if (st.size()) {
                L[i] += 1LL*(i - st.back())*heights[i];
                L[i] += L[st.back()];
            } else {
                L[i] = 1LL*(i + 1)*heights[i];
            }
            st.push_back(i);
        }
    }
    long long maximumSumOfHeights(vector<int>& heights) {
        int n = heights.size();
        vector<long long> L(n), R(n);
        fill(heights, L);
        reverse(heights.begin(), heights.end());
        fill(heights, R);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = n - i - 1;
            long long cur = L[l] + R[r] - heights[r];
            ans = max(ans, cur);
        }
        return ans;
    }
};