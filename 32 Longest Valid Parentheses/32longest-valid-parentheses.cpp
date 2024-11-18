class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> rightIdx(n, -1);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') st.push_back(i);
            else {
                if (st.size()) {
                    rightIdx[st.back()] = i;
                    st.pop_back();
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n;) {
            if (rightIdx[i] == -1) {
                i++; continue;
            }
            int len = 0;
            while (i < n && rightIdx[i] != -1) {
                len += (rightIdx[i] - i + 1);
                i = rightIdx[i];
                i++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};