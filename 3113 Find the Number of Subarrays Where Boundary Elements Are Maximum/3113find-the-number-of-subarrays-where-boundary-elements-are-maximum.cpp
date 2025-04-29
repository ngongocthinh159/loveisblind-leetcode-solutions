class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> st;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            while (st.size() && nums[st.back().first] < nums[i]) st.pop_back();
            if (!st.size() || nums[st.back().first] > nums[i])
                st.push_back({i, 0});
            ans += ++st.back().second;
        }
        return ans;
    }
};  