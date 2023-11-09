class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int l = 0, r = 0;
        while (r < nums.size()) {
            while (r < nums.size() && (r - l) <= k - 1) {
                if (st.find(nums[r]) != st.end()) return true;
                else st.insert(nums[r]);
                r++;
            }

            if (r < nums.size()) {
                if (st.find(nums[r]) != st.end()) return true;
                else {st.insert(nums[r]); st.erase(nums[l]); l++;};
                r++;
            }
        }
        return false;
    }
};