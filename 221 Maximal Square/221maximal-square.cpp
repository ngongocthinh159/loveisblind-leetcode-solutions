class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> h(m), L(m), R(m);
        int ans = 0;
        vector<int> st;
        for (int i = 0; i < n; i++) {
            st.clear();
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') 
                    h[j]++;
                else 
                    h[j] = 0;
                while (st.size() && h[j] <= h[st.back()]) st.pop_back();
                if (st.size())
                    L[j] = st.back();
                else
                    L[j] = -1;
                st.push_back(j);
            }
            st.clear();
            for (int j = m - 1; j >= 0; j--) {
                while (st.size() && h[j] <= h[st.back()]) st.pop_back();
                if (st.size())
                    R[j] = st.back();
                else
                    R[j] = m;
                st.push_back(j);
                int len = min(h[j], R[j] - L[j] - 1);
                ans = max(ans, len * len);
            }
        }
        return ans;
    }
};