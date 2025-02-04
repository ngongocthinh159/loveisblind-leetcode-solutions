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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> L(n), R(n);
        fill(maxHeights, L);
        reverse(maxHeights.begin(), maxHeights.end());
        fill(maxHeights, R);
        reverse(maxHeights.begin(), maxHeights.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, L[i] + R[n - i - 1] - maxHeights[i]);
        }
        return ans;
    }
};