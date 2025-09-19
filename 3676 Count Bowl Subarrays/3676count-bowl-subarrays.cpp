class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> st, L(n), R(n);
        for (int i = 0; i < n; i++) {
            while (st.size() && nums[st.back()] <= nums[i]) st.pop_back();
            if (st.size()) 
                L[i] = st.back();
            else 
                L[i] = -1;
            st.push_back(i);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && nums[st.back()] <= nums[i]) st.pop_back();
            if (st.size())
                R[i] = st.back();
            else
                R[i] = n;
            st.push_back(i);
        }
        long long ans = 0;
        for (int i = 0; i< n; i++) {
            if (L[i] != -1 && R[i] != n) ans++;
        }
        return ans;
    }
};