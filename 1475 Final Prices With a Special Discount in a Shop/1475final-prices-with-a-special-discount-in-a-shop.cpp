class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> nextSmallerOrEqual(n);
        vector<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && prices[st.back()] > prices[i]) st.pop_back();
            if (st.size()) nextSmallerOrEqual[i] = st.back();
            else nextSmallerOrEqual[i] = -1;
            st.push_back(i); 
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = prices[i] - (nextSmallerOrEqual[i] == -1 ? 0 : prices[nextSmallerOrEqual[i]]);
        }
        return ans;
    }
};